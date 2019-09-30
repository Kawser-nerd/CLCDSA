using System;
using System.Collections.Generic;
using System.Linq;

namespace atcoder{
    class prob{
        const long mo = 1000000000 + 7;
        static long[] inv;
        static public int Main(){
            inv = new long[901];
            for(int i=0;i<=900;i++)
                inv[i] = pow(i);

            var any = Enumerable.Range(0,3).Select(_=>Console.ReadLine().Split().Select(e=>long.Parse(e)).ToArray()).ToArray();
            long r=any[0][0], c=any[0][1], x=any[1][0], y=any[1][1], d=any[2][0], l=any[2][1];

            long m=0;
            for(int i=0;i<(1<<4);i++){
                long xx = x, yy = y;
                if((i&1)!=0) xx--;
                if((i&2)!=0) xx--;
                if((i&4)!=0) yy--;
                if((i&8)!=0) yy--;

                if(xx<0 || yy<0)
                    continue;
                
                int b = i;
                b = (b&0x5) + ((b>>1)&0x5);
                b = (b&0x3) + ((b>>2)&0x3);
                if(b%2==0){
                    m += comb(xx*yy, d+l);
                }
                else{
                    m -= comb(xx*yy, d+l);
                }
                m %= mo;
            }

            m *= comb(d+l, d);
            m %= mo;
            m *= (r-x+1)*(c-y+1);
            m %= mo;
            m += mo;
            m %= mo;

            Console.WriteLine(m);

            return 0;
        }
        static long pow(long x, long y=mo-2, long mo=mo){
            long z = 1;
            for(long i=1;y>=i;i<<=1){
                if((y&i)!=0) z=z*x%mo;
                x = x*x%mo;
            }
            return z;
        }
        static long comb(long x, long y){
            if(x<y)
                return 0;
            if(x<y*2)
                y = x-y;
            long res = 1;
            for(long i=x;i>x-y;i--){
                res *= i;
                res %= mo;
            }
            for(long i=y;i>0;i--){
                res *= inv[i];
                res %= mo;
            }
            return res;
        }
    }
}