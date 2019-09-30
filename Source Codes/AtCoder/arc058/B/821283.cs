using System;
using System.Linq;

namespace ABC042_D
{
    class Program
    {      
        static void Main(string[] args)
        {
            var a = scan();
            maketable(a[0], a[1]);
            long ans = 0;
            for (long i =a[3]; i < a[1]; i++)
            {
                long ue = getC(a[0] - a[2] - 1, i);
                long shita = getC(a[2]-1,a[1]-i-1);             
                ans += ue * shita;
                ans %= q;
            }
            Console.WriteLine(ans);
        }

        const int q = 1000000007;
        static long[] t = new long[200000];
        static long[] s = new long[200000];

        
        //(a+b)!/a!b!?a+bCa????
        static long getC(long a,long b)
        {
            return(((t[a+b]*s[a])% q)*s[b])%q;           
        }
        
        // x! ?(x!)^-1?table???????
        static void maketable(long H,long W)
        {
            t[0] = 1;
            long i;
            for (i = 1; i < H+W-1; i++)
            {
                t[i] = (i*t[i - 1])%q;   
            }

            i--;
            s[i] = powmod(t[i],q-2, q);

            for (; i > 0; i--)
            {
                s[i-1] = (s[i] * i) % q;
            }
        }
       
        //a^b(modq)
        static long powmod(long a, long b, long p)
        {
            if (b == 0) return 1;
            if (b % 2 == 0)
            {
                long d = powmod(a, b / 2, p);
                return (d * d) % p;
            }
            else return (a * powmod(a, b - 1, p)) % p;         
        }

        static long[] scan()
        {
            return
               Console.ReadLine().Split(' ')
               .Select(i => long.Parse(i)).ToArray();
        }
    }

}