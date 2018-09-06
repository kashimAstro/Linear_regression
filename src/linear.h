#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <vector>

using namespace std;

class linear_regression {
	public:

	void linear(vector<float> x, vector<float> y){
	    float sumx=0,sumy=0,sumxy=0,sumx2=0;
	    double a,b;
	    int n = x.size();
	    x.resize(n);
            y.resize(n);
	    for(int i = 0; i <= n-1; i++)
	    {
		sumx  = sumx  +x[i];
		sumx2 = sumx2 +x[i]*x[i];
		sumy  = sumy  +y[i];
		sumxy = sumxy +x[i]*y[i];
	    }
	    a = ((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
	    b = ((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
	    printf("Y=%3.3f+%3.3fX",a,b);
	}

	void exponential(vector<float> x, vector<float> y){
            int n = x.size();
	    x.resize(n);
            y.resize(n);

	    float Y[n],sumx=0,sumy=0,sumxy=0,sumx2=0;
	    double a,b,A;
	    for(int i=0;i<=n-1;i++)
	    {
		Y[i]=log(y[i]);
	    }
	    for(int i=0;i<=n-1;i++)
	    {
		sumx=sumx +x[i];
		sumx2=sumx2 +x[i]*x[i];
		sumy=sumy +Y[i];
		sumxy=sumxy +x[i]*Y[i];

	    }
	    A=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
	    b=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
	    a=exp(A);
	    printf("Y=%4.3fe^%4.3fX",a,b);
	}

	void polynomial(vector<float> x, vector<float> y, int degress){
            int N = x.size();
	    x.resize(N);
            y.resize(N);
	    int n = degress;
	    double X[2*n+1];
	    for (int i=0;i<2*n+1;i++)
	    {
		X[i]=0;
		for (int j=0;j<N;j++)
		    X[i]=X[i]+pow(x[j],i);
	    }
	    double B[n+1][n+2],a[n+1];
	    for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
		    B[i][j]=X[i+j];
	    double Y[n+1];
	    for (int i=0;i<n+1;i++)
	    {
		Y[i]=0;
		for (int j=0;j<N;j++)
		    Y[i]=Y[i]+pow(x[j],i)*y[j];
	    }
	    for (int i=0;i<=n;i++)
		B[i][n+1]=Y[i];
	    n=n+1;
	    for (int i=0;i<n;i++)
		for (int k=i+1;k<n;k++)
		    if (B[i][i]<B[k][i])
			for (int j=0;j<=n;j++)
			{
			    double temp=B[i][j];
			    B[i][j]=B[k][j];
			    B[k][j]=temp;
			}

	    for (int i=0;i<n-1;i++)
		for (int k=i+1;k<n;k++)
		{
		    double t=B[k][i]/B[i][i];
		    for (int j=0;j<=n;j++)
			B[k][j]=B[k][j]-t*B[i][j];
		}
	    for (int i=n-1;i>=0;i--)
	    {
		a[i]=B[i][n];
		for (int j=0;j<n;j++)
		    if (j!=i)
			a[i]=a[i]-B[i][j]*a[j];
		a[i]=a[i]/B[i][i];
	    }
	    cout<<"Y=";
	    for (int i=0;i<n;i++)
		cout<<"+("<<a[i]<<")"<<"x^"<<i;
	}
};

