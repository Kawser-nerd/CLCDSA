using System;
using System.Collections.Generic;
class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int a = int.Parse(input[0]), b = int.Parse(input[1]), q = int.Parse(input[2]);

            long[] s = new long[a];
            for (int i=0; i<a; i++) s[i] = long.Parse(Console.ReadLine());

            long[] t = new long[b];
            for (int i=0; i<b; i++) t[i] = long.Parse(Console.ReadLine()); 

            for (int i=0; i<q; i++)
            {
                long x = long.Parse(Console.ReadLine());
                int al = -1, bl = -1;
                int ar = a, br = b;
                while (ar - al > 1)
                {
                    int ap = (ar + al) / 2;
                    if (s[ap] > x) ar = ap;
                    else al = ap;
                } 
                while (br -bl > 1)
                {
                    int bp = (br + bl) / 2;
                    if (t[bp] > x) br = bp;
                    else bl = bp;
                }
                
                long alPos, arPos, blPos, brPos;
                if (al == -1) alPos = -10000000000;
                else alPos = s[al];
                if (ar == a) arPos = 20000000000;
                else arPos = s[ar];
                if (bl == -1) blPos = -10000000000; 
                else blPos = t[bl];
                if (br == b) brPos = 20000000000;
                else brPos = t[br];
                long ans1 = Math.Max(arPos, brPos) - x;
                long ans2 = x - Math.Min(alPos, blPos);
                long aNear = Math.Min(arPos-x, x-alPos);
                long bNear = Math.Min(brPos-x, x-blPos);
                long ans3 = aNear + bNear + Math.Min(aNear, bNear);
                long ans = Math.Min(ans1, Math.Min(ans2, ans3));
                Console.WriteLine(ans);

            }
        }
    }
    //mcs Main.cs
    //mono Main.exe