#include<stdio.h>
#include<math.h>


int main(){
	int T,N;
	double err = 1e-10;
	double dmin,tmin;
	double k,s,t;
	long int suma,sumb,sumc,sumx,sumy,sumz;
	int x[600],y[600],z[600],a[600],b[600],c[600];
	int i,j;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%d",&N);
		for(j=0;j<N;j++){
			scanf("%d%d%d%d%d%d",&x[j],&y[j],&z[j],&a[j],&b[j],&c[j]);
			//printf("%lf %lf %lf %lf %lf %lf\n",x[j],y[j],z[j],a[j],b[j],c[j]);
		}
		suma = sumb = sumc = sumx = sumy = sumz = 0;
		for(j=0;j<N;j++){
			suma += a[j];
			sumb += b[j];
			sumc += c[j];
			sumx += x[j];
			sumy += y[j];
			sumz += z[j];
		}
		//printf("%f %f %f %f %f %f\n",suma,sumb,sumc,sumx,sumy,sumz);
		k = suma*suma + sumb*sumb + sumc*sumc;
		s = sumx*suma + sumy*sumb + sumz*sumc;
		if(k==0) tmin = err;
		else 
		{t = -s*1.0/(k*1.0);
		if(t<err) tmin = err;
		else tmin = t;
		}
		dmin = sumx*sumx + tmin*tmin*suma*suma+ 2*tmin*suma*sumx+ sumy*sumy + tmin*tmin*sumb*sumb+ 2*tmin*sumb*sumy + sumz*sumz + tmin*tmin*sumc*sumc + 2*tmin*sumc*sumz;
		dmin = sqrt(fabs(dmin)/(N*N*1.0));
		//dmin = sqrt(fabs(dmin));
		printf("Case #%d: %.8lf %.8lf\n",i,dmin,tmin);
	}
	return 0;
}
