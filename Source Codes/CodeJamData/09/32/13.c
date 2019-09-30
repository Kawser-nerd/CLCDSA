#include<stdio.h>
#include<math.h>

int main()
{
    int T,i,N,j;
    double vxc,vyc,vzc,xc,yc,zc;
    int ix,iy,iz,ivx,ivy,ivz;
    double x,y,z,vx,vy,vz,t,d;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d",&N);
        xc=0;yc=0;zc=0;vxc=0;vyc=0;vzc=0;
        for(j=0;j<N;j++)
        {
            scanf("%d%d%d%d%d%d",&ix,&iy,&iz,&ivx,&ivy,&ivz);
            xc=xc+ix;yc=yc+iy;zc=zc+iz;vxc=vxc+ivx;vyc=vyc+ivy;vzc=vzc+ivz;
        }
        x=xc/N;y=yc/N;z=zc/N;vx=vxc/N;vy=vyc/N;vz=vzc/N;/*CM & VofCM*/
        t=-1*(x*vx+y*vy+z*vz)/ (vx*vx+vy*vy+vz*vz);
        if( t > 0 )
        {
            x=x+vx*t;y=y+vy*t;z=z+vz*t;
            d=sqrt(x*x+y*y+z*z);
            printf("Case #%d: %lf %lf\n",i,d,t);
        }
        else
        {
            t=0;
            d=sqrt(x*x+y*y+z*z);
            printf("Case #%d: %lf %lf\n",i,d,t);
        }
    }
    return 0;
}
