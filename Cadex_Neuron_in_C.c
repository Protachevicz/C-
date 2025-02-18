#include<math.h>
#include<stdio.h>
#include<stdlib.h>
//%%%%%%%%%--Randon numbers Parameters--%%%%%%%%%%%%%
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
#define NR_END 1
#define FREE_ARG char*
float ran1(long *idum);
void nrerror(char error_text[]);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define N 500
#define EQ 2*N
#define Ref 5.0 // Refratario
#define Dmax 800
int conex[N],list[N][N];
void derivs(float y[],float ydot[],float I0[],float s[],float g[],float ei[],float tauA[],float gAb[],float VA[],float C[],float EL[]);
int main(){
				long idum;
				int i,ik,j,k,l,m,prf[N],crf[N],contISI,contd[N],ij[N],ij2[N],AJ0[N][N],AJ1[N][N];
				float h,h0[N],t,tr,tf,VR[N],VD,deltagA[N],c1[EQ],c2[EQ],c3[EQ],gex,gin,diag[5],tau_ex,tau_in,EL[N],NP[N],gext,
				x[EQ],y[EQ],ydot[EQ],I0[N],vec[N][Dmax],isi[2],s[N],ww[N],ei[N],g[N],p,local,rate,tauA[N],gAb[N],VA[N],C[N];
				char file1[100],file2[100];
				FILE *fs,*fp;
				ik=1;
				sprintf(file1,"raster%d.dat",ik);
				fs=fopen(file1,"w");
				sprintf(file2,"diags%d.dat",ik);
				fp=fopen(file2,"w");
				h=0.01; VD=-40.0;
				//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				//%%%%%%%%%%%%%%%%%%%%%%%%%%--Parâmetros--%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                                  
				p=0.02;  // probabilidade de reconexão (p=0 regular), (p=1 aleatória)     
				local=(int)(0.053*N); // conexões locais de cada lado do sítio i
				tf=5000.0;            // tempo final da simulação
				tr=1000.0; // transiente
				gex=0.001;   // intensidade excitatória
				gin=0.0;   // intensidade inibitória
				gext=0.5;   // intensidade excitatória
				tau_ex=10.0; // tau do excitatório
				tau_in=5.0; // tau do inibitório
				rate=0.5;  // taxa do Poisson



				//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				//%%%%%%%%%%%%%--Excit/Inib--%%%%%%%%%%%%%%%%%
				for(i=0;i<N;i++){
								conex[i]=0;
								for(j=0;j<N;j++){
												list[i][j]=-1;
												AJ0[i][j]=AJ1[i][j]=0;
								}
				}
				//%%%%%%%%%%%%%%%%%%--network--%%%%%%%%%%%%%%%
				//%%%%%%%%%%%%%%%%--local-conections--%%%%%%%%
				idum=-847245973165; m=local;
				for(i=0;i<N;i++)
								for(j=0;j<N;j++){
												if((i!=j)&&((abs(i-j)<=m)||(abs(i-j)>=(N-m)))){
																list[i][conex[i]]=j; conex[i]++; AJ0[i][j]=1; 
												}
								}
				//%%%%%%%%--random longer conections--%%%%%%%%
				for(i=0;i<N;i++){
								for(j=0;j<N;j++){
												if((AJ0[i][j]==1)&&(AJ1[i][j]==0)){
																if(ran1(&idum)<=p){
																				AJ0[i][j]=k=0;
																				while(k==0){
																								l=(int)(N*ran1(&idum));
																								if(l==N)
																												l=0;
																								if((l!=j)&&(l!=i)&&(AJ0[i][l]==0)&&(AJ1[i][j]==0)){
																												k=1; AJ0[i][l]=AJ1[i][l]=1; 
																												list[i][conex[i]]=l; conex[i]++;
																								}
																				}
																}
												}
								}
				}
				//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				k=0;
				for(i=0;i<N;i++){
								y[i]=x[i]=-80.0+20.0*ran1(&idum);
								y[i+N]=x[i+N]=10.0+10.0*ran1(&idum);
								prf[i]=2*tf;
								crf[i]=contd[i]=0;
								for(j=0;j<Dmax;j++)
												vec[i][j]=0.0;
								ij[i]=ij2[i]=10000000;
								ww[i]=tf+tf*ran1(&idum);
								vec[i][0]=tr-tr*ran1(&idum);
								vec[i][1]=ww[i];
								ei[i]=0.0;
								g[i]=gex;
								h0[i]=h/tau_ex;
								deltagA[i]=1.0;
								tauA[i]=200.0;
								gAb[i]=10.0;
								VA[i]=-50.0;
								C[i]=200.0;//100.0+100.0*ran1(&idum);
								EL[i]=-60.0;
								NP[i]=0.0;
								//%%%%%%%%%%%%-- 1 inibitório a cada 4 excitatório--%%%%%%%%%%%%%%%
								if(k==4)
								{
												ei[i]=-80.0;
												g[i]=gin;
												h0[i]=h/tau_in;
												deltagA[i]=0.0;
												tauA[i]=40.0;
												gAb[i]=2.0;
												VA[i]=-45.0;
												//C[i]=200.0+100.0*ran1(&idum);
												EL[i]=-70.0;
												k=-1;
								}
								k++;
								//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				}
				//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				l=contISI=j=k=m=0;
				diag[0]=diag[1]=0.0;
				diag[2]=diag[3]=0.0;
				isi[0]=isi[1]=diag[4]=0.0;
				for(t=0.0;t<tf;t+=h){
								i=0;
								fprintf(fp,"%f\t%f\t%f\t%f\n",t,y[i],I0[i],NP[i]);
								
								for(i=0;i<N;i++){
									NP[i]=NP[i]*exp(-0.001);
												s[i]=exp(-ij[i]*h0[i]); ij[i]++; 
												I0[i]=NP[i]*(0.0-y[i]);
												if(ran1(&idum)<(1.0-exp(-rate*h))){
			
																NP[i]=NP[i]+gext;
												}
											
								}
								//%%%%%%%%%%%%%%%%%%%%%%%%%%
								derivs(y,ydot,I0,s,g,ei,tauA,gAb,VA,C,EL);
								for(i=0;i<EQ;i++){
												c1[i]=h*ydot[i];
												y[i]=x[i]+c1[i]*0.5;
								}
								derivs(y,ydot,I0,s,g,ei,tauA,gAb,VA,C,EL);
								for(i=0;i<EQ;i++){
												c2[i]=h*ydot[i];
												y[i]=x[i]+c2[i]*0.5;
								}
								derivs(y,ydot,I0,s,g,ei,tauA,gAb,VA,C,EL);
								for(i=0;i<EQ;i++){
												c3[i]=h*ydot[i];
												y[i]=x[i]+c3[i];
								}
								derivs(y,ydot,I0,s,g,ei,tauA,gAb,VA,C,EL);
								for(i=0;i<EQ;i++)
												y[i]=x[i]+(c1[i]+h*ydot[i])/6.0+(c2[i]+c3[i])/3.0;
								//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
								for(i=0;i<N;i++){
												if((crf[i]==0)&&(y[i]>=VD)){
																crf[i]=1; y[i+N]+=deltagA[i]; prf[i]=t+Ref;
																if(t>tr){
																				fprintf(fs,"%f\t%d\n",t,i);
																				if(contd[i]<Dmax-1){
																								contd[i]++;
																								vec[i][contd[i]]=t;
																								vec[i][contd[i]+1]=ww[i];
																								if(contd[i]>1){
																												contISI++;
																												isi[0]=isi[0]+(t-vec[i][contd[i]-1]);
																												isi[1]=isi[1]+(t-vec[i][contd[i]-1])*(t-vec[i][contd[i]-1]);
																								}
																				}
																}
												}
												//%%%%%%%%%%%%%%%%%--REFRATARIO--%%%%%%%%%%%%%%%%%
												if(crf[i]==1)
																y[i]=VR[i];
												if(t>=prf[i]){
																crf[i]=ij[i]=0;
												}
												x[i]=y[i]; x[i+N]=y[i+N];
								}
				}
				//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				if(contISI>0){
								isi[0]=isi[0]/contISI;
								isi[1]=isi[1]/contISI;
								isi[1]=fabs(isi[1]-isi[0]*isi[0]);
								if(isi[0]>0.0){
												diag[0]=sqrt(isi[1])/isi[0];
												diag[1]=1000.0/isi[0];
								}
				}
				//%%%%%%%%%%%%%%%%%%%%--parametro de ordem--%%%%%%%%%%%%%%
				for(i=0;i<N;i++){
								ydot[i]=s[i]=0.0;
								ij[i]=prf[i]=0;
								contd[i]=contd[i]-1;
				}
				j=k=0;
				x[2]=0.0;
				for(t=0.0;t<tf-200;t+=20.0*h){
								for(i=0;i<N;i++){
												y[i]=s[i];
												s[i]=6.28*(t-vec[i][ij[i]])/(vec[i][ij[i]+1]-vec[i][ij[i]]);
												if((t>vec[i][ij[i]+1])&&(ij[i]<contd[i]))
																ij[i]++;
								}
								if(t>tr){
												x[0]=x[1]=0.0;
												for(i=0;i<N;i++){
																if(contd[i]>-1){
																				prf[i]=1;
																				x[0]=x[0]+cos(s[i]);
																				x[1]=x[1]+sin(s[i]);
																}
												}
												j++; l++;
												x[0]=x[0]/N; x[1]=x[1]/N;
												x[2]=x[2]+sqrt(x[0]*x[0]+x[1]*x[1]);
								}
				}
				diag[2]=x[2]/j; 
				x[0]=0.0;
				for(i=0;i<N;i++){
								k=k+prf[i];
								x[0]=x[0]+I0[i];
				}
				diag[3]=k*1.0/N;
				diag[4]=x[0]/N;
				//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
				printf(" gin=%f; gex=%f; cv=%f; freq=%f Hz; ord=%f; ativos=%f; IPoisson=%f\n",gin,gex,diag[0],diag[1],diag[2],diag[3],diag[4]);
				fclose(fs); fclose(fp); return(0);
}
void derivs(float y[],float ydot[],float I0[],float s[],float g[],float ei[],float tauA[],float gAb[],float VA[],float C[],float EL[]){
				int i,j;
				float EA,deltaA,VT,gL,deltaT[2],z[N];
				EA=-70.0;
				deltaA=1.0/5.0;
				VT=-50.0;
				gL=10.0;
				deltaT[0]=2.0;
				deltaT[1]=1.0/deltaT[0];
				for(i=0;i<N;i++){
								z[i]=0.0;
								for(j=0;j<conex[i];j++)
												z[i]=z[i]+g[list[i][j]]*(ei[list[i][j]]-y[i])*s[list[i][j]];
								ydot[i]=(gL*((EL[i]-y[i])+deltaT[0]*exp((y[i]-VT)*deltaT[1]))+y[i+N]*(EA-y[i])+I0[i]+z[i])/C[i];
								ydot[i+N]=(gAb[i]/(1.0+exp((VA[i]-y[i])*deltaA))-y[i+N])/tauA[i];
				}
}
//%%%%%%%%%%%%%%%%%%%%%%%--GERADOR-RANDOMICO--%%%%%%%%%%%%%%%
float ran1(long *idum){
				int j; long k;
				static long iy=0;
				static long iv[NTAB];
				float temp; 
				if(*idum<=0 || !iy){
								if(-(*idum)<1)
												*idum=1;
								else
												*idum=-(*idum);
								for(j=NTAB+7;j>=0;j--){
												k=(*idum)/IQ;
												*idum=IA*(*idum-k*IQ)-IR*k;
												if(*idum<0) 
																*idum +=IM;
												if(j<NTAB) 
																iv[j]=*idum;
								}
								iy=iv[0];
				}
				k=(*idum)/IQ;
				*idum=IA*(*idum-k*IQ)-IR*k;
				if(*idum<0)
								*idum += IM;
				j=iy/NDIV; iy=iv[j];
				iv[j]=*idum;
				if((temp=AM*iy)>RNMX)
								return RNMX;
				else 
								return temp;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void nrerror(char error_text[]){
				fprintf(stderr,"Numerical Recipes run-time error...\n");
				fprintf(stderr,"%s\n",error_text);
				fprintf(stderr,"...now exiting to system...\n");
				exit(1);
}
