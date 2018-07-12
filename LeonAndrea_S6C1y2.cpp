#include <iostream>
using namespace std;
#include <math.h>

int main(){
	int nx=100;
	double p=10.0;	
	double r=40.0;
	double c= sqrt(r/p);
	double xf=100.0;
	double dx=xf/nx;
	double dt=dx/(c*2);
	double tf=200;
	int nt=tf/dt;
	double up[nx];
	double uf[nx];	
	double upa[nx];
	up[0]=0.0;
	up[nx-1]=0.0;
	uf[0]=0.0;
	uf[nx-1]=0.0;
	upa[nx-1]=0.0;
	upa[0]=0.0;
	int con=0;
	double radio=c*dt/dx;
	
	for(int j=0; j<=nt ; j++)
	{
		for(int i=1; i<nx-1 ; i++)
		{	
				up[0]=0.0;
				up[nx-1]=0.0;
				uf[0]=0.0;
				uf[nx-1]=0.0;
				upa[nx-1]=0.0;
				upa[0]=0.0;
			if(j==0 && ( i<=(0.8*xf)))
			{
				upa[i]=1.25*i/xf;
			}
			if( j==0 && i>(0.8*xf))
			{
				upa[i]=5.0-(5.0*i/xf);
				
			}
			if(j==1)
			{
				up[i]=upa[i]+((radio*radio)/2)*(upa[i+1]-2*upa[i]+upa[i-1]);
			}
			if(j!=1 && j!=0)
			{	
				con=3;
				uf[i]=(c*c)*((dt*dt)/(dx*dx))*(up[i+1]-(2*up[i])+up[i-1])+(2*up[i])-upa[i];
				upa[nx-1]=0.0;
				up[nx-1]=0.0;
				uf[nx-1]=0.0;				
			}
		}
		
		for(int k=0; k<nx ; k++)
		{
			if(con==3)
			{
				upa[k]=up[k];
				up[k]=uf[k];	
			}
			cout << k << "	" <<up[k] << endl;
		}	
	}

	return 0;
}
