#include <stdio.h>
int tt,test,i,j,k,n,a,b,c,d,e,f;
int main() {
    FILE * fin = fopen("fire2.in","r");
    FILE * fout= fopen("fire2.out","w");
    fscanf(fin,"%d\n",&test);
    double t,x,y,z,vx,vy,vz;
    for (tt=1; tt<=test; tt++) {
        fscanf(fin,"%d",&n);
        x = y = z = vx =vy = vz =0;
        for (i=1; i<=n; i++) {
          fscanf(fin,"%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
          x+=a; y+=b; z+=c; vx+=d; vy+=e; vz+=f;
        }
        x/=n; y/=n; z/=n;
        vx/=n; vy/=n; vz/=n;
        if (vx*vx+vy*vy+vz*vz<0.0000000001)
           t = 0;
           else t = -(x*vx+y*vy+z*vz) / (vx*vx+vy*vy+vz*vz);
        if (t<0) t = 0;   
        x = x+ t*vx;
        y = y+ t*vy;
        z = z+ t*vz;
        fprintf(fout,"Case #%d: %0.8f %0.8f\n",tt,sqrt(x*x+y*y+z*z),t);
    }
    return 0;
}
