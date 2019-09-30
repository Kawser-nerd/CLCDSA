#include <stdio.h>
#include <math.h>

/******************************************************************************
Compiler + OS: gcc 3.4.4 + (Cygwin + Windows XP SP3)
Editor: Notepad++ v5.3.1

to compile: gcc -lm b.c
to run: ./a.exe file_name.in > file_name.out
******************************************************************************/

/*================================================================== SYMB ===*/
#define T_MAX    500
#define BUF_MAX 1024

#define ERR_ARGS    -1
#define ERR_NOFILE  -2
#define ERR_BADPAR  -3


#define INI_PARAMS  1


/*================================================================== DECL ===*/


/*================================================================== MAIN ===*/
int main(int argc, char* argv[])
{
    FILE* f_in;
    
    int   T;
    
    int   i, j;
    int   N;
    int   x, y, z, vx, vy, vz;
    
    double xm, ym, zm, vxm, vym, vzm, tmin, dmin, ux, uy, uz;
    
    char buf[BUF_MAX+1];

    
    if(argc != 2) {
        return ERR_ARGS;
    }
    
    f_in = fopen(argv[1], "rb");
    if(f_in == NULL) {
        return ERR_NOFILE;
    }
    
    /* Read parameters */
    fgets(buf, BUF_MAX, f_in);
    if(INI_PARAMS != sscanf(buf, "%d", &T)  ||  1>T  ||  T>T_MAX) {
        return ERR_BADPAR;
    }

    
    /* Scan inputs  and compute stuff*/
    for(i=1; i<=T; ++i) {
        /* scan number of fireflies */
        fgets(buf, BUF_MAX, f_in);
        sscanf(buf, "%d", &N);
        
        /* Scan each fireflie */
        xm=ym=zm=0.0;
        vxm=vym=vzm=0.0;
        for(j=0; j<N; ++j) {
            fgets(buf, BUF_MAX, f_in);
            sscanf(buf, "%d %d %d %d %d %d", &x, &y, &z, &vx, &vy, &vz);
            xm += x;
            ym += y;
            zm += z;
            vxm += vx;
            vym += vy;
            vzm += vz;
        }
        
        /* Compute average */
        xm /= N;
        ym /= N;
        zm /= N;
        vxm /= N;
        vym /= N;
        vzm /= N;
        
        /* Compute mintime */
        if(vxm==0.0 && vym==0.0 && vzm==0.0) {
            tmin = 0.0;
        } else {
            tmin = - (xm*vxm + ym*vym + zm*vzm)/(vxm*vxm + vym*vym + vzm*vzm);
            if(tmin<0.0) {
                tmin = 0.0;
            }
        }
        
        /* Compute mindist */
        ux = xm + vxm*tmin;
        uy = ym + vym*tmin;
        uz = zm + vzm*tmin;
        
        dmin = sqrt(ux*ux + uy*uy + uz*uz);
        
        /* Print result */
        fprintf(stdout, "Case #%d: %.8f %.8f\n", i, dmin, tmin);
    }
    return 0;
}


/*================================================================== IMPL ===*/
