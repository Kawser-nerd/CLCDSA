#include<stdio.h>
#include<math.h>

int main(){
    int t, n,x,y,z,vx,vy,vz;
    double xM,yM,zM,vxM,vyM,vzM;
    int caso = 0,i;

    double dmin, tmin;

    scanf("%d",&t);
    while(t--){
        xM=yM=zM=vxM=vyM=vzM=0;
        scanf("%d",&n);
        i=0;
        while(i<n){
            scanf("%d %d %d %d %d %d",&x,&y,&z,&vx,&vy,&vz);
            xM = xM + x;
            yM = yM + y;
            zM = zM + z;
            vxM = vxM + vx;
            vyM = vyM + vy;
            vzM = vzM + vz;
            i++;
        }
        xM = xM/n;
        yM = yM/n;
        zM = zM/n;
        vxM = vxM/n;
        vyM = vyM/n;
        vzM = vzM/n;

        if(vxM*vxM + vyM*vyM + vzM*vzM !=0){
            tmin = -1*(xM*vxM + yM*vyM + zM*vzM) / (vxM*vxM + vyM*vyM + vzM*vzM);
            if(tmin < 0) tmin = 0;
            dmin = (xM*xM + 2*xM*vxM*tmin + vxM*tmin*vxM*tmin) + (yM*yM + 2*yM*vyM*tmin + vyM*tmin*vyM*tmin) + (zM*zM + 2*zM*vzM*tmin + vzM*tmin*vzM*tmin);
            if(dmin<0) dmin = -1*dmin;
            dmin = sqrt(dmin);
        }
        else if(xM*vxM + yM*vyM + zM*vzM){
            tmin = xM*xM + yM*yM + zM*zM;
            tmin = -1*tmin;
            tmin = tmin / 2;
            tmin = tmin / (xM*vxM + yM*vyM + zM*vzM);
            dmin = 0.0;
        }
        else{
            dmin = xM*xM + yM*yM + zM*zM;
            dmin = sqrt(dmin);
            tmin = 0.0;
        }


        printf("Case #%d: %lf %lf\n",++caso,dmin,tmin);
    }

}
