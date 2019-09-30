using System;
using System.Collections.Generic;
using System.Linq;

namespace CSharpSample01
{

    

    class Program
    {

        static long[] shrine;
        static long[] temple;
        static long[] posi;
        static int A;
        static int B;
        static int Q;
        const long EAST = 100000000000;
        const long WEST = -100000000000;
        
        static int LowerBound(long[] data, long key)
        {
            int left = -1;
            int right = data.Count();

            while(right - left > 1)
            {
                int mid = left + (right - left) / 2;

                if(data[mid] >= key)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }

            }


            return right;
        }
        

        static void Main(string[] args)
        {
            string[] str = Console.ReadLine().Split(' ');
            A = int.Parse(str[0]);
            B = int.Parse(str[1]);
            Q = int.Parse(str[2]);

            shrine = new long[A];
            temple = new long[B];
            posi = new long[Q];

            for(int i = 0; i < A; i++)
            {
                shrine[i] = long.Parse(Console.ReadLine());
            }

            for(int i = 0; i < B; i++)
            {
                temple[i] = long.Parse(Console.ReadLine());
            }

            for(int i = 0; i < Q; i++)
            {
                posi[i] = long.Parse(Console.ReadLine());
            }


            
            int right = 0;
            long s1, s2;
            long t1, t2;
            for(int i = 0; i < Q; i++)
            {
                long x = posi[i];

                right = LowerBound(shrine, x);
                if(right == A)
                {
                    s1 = shrine[right - 1];
                    s2 = EAST;
                }
                else if(right == 0)
                {
                    s1 = WEST;
                    s2 = shrine[right];
                }
                else
                {
                    s1 = shrine[right - 1];
                    s2 = shrine[right];
                }

                right = LowerBound(temple, x);
                if (right == B)
                {
                    t1 = temple[right - 1];
                    t2 = EAST;
                }
                else if (right == 0)
                {
                    t1 = WEST;
                    t2 = temple[right];
                }
                else
                {
                    t1 = temple[right - 1];
                    t2 = temple[right];
                }

                var cstlist = new List<long>();

                cstlist.Add(Math.Abs(x - s1) + Math.Abs(t1 - s1));
                cstlist.Add(Math.Abs(x - s1) + Math.Abs(t2 - s1));
                cstlist.Add(Math.Abs(x - s2) + Math.Abs(t1 - s2));
                cstlist.Add(Math.Abs(x - s2) + Math.Abs(t2 - s2));

                cstlist.Add(Math.Abs(x - t1) + Math.Abs(s1 - t1));
                cstlist.Add(Math.Abs(x - t1) + Math.Abs(s2 - t1));
                cstlist.Add(Math.Abs(x - t2) + Math.Abs(s1 - t2));
                cstlist.Add(Math.Abs(x - t2) + Math.Abs(s2 - t2));

                cstlist.Sort();

                Console.WriteLine(cstlist.First());

            }
            

        }
    }
}