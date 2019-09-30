using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Practice
{
    class Program
    {
        private static int ReadAndParseInt()
        {
            return int.Parse(Console.ReadLine());
        }
        private static int[] ReadAndParseIntArr()
        {
            return Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        }
        private static long ReadAndParseLong()
        {
            return long.Parse(Console.ReadLine());
        }
        private static long[] ReadAndParseLongArr()
        {
            return Array.ConvertAll(Console.ReadLine().Split(' '), long.Parse);
        }
        static void Main(string[] args)
        {
            SolveA(args);
            //SolveB(args);
            //SolveC(args);
            //SolveD(args);


        }

        static void SolveA(string[] args)
        {
            int n = ReadAndParseInt();
            bool[] isprime = eratos(55555);
            List<int> prime = new List<int>();
            for(int i=2;i<isprime.Length;++i)
            {
                if (i > 55555) { break; }
                if(isprime[i]) { prime.Add(i); }
            }

            var ans = new List<int>();
            for(int i=0;i<prime.Count;++i)
            {
                if( prime[i] % 5 == 1)
                {
                    ans.Add(prime[i]);
                    if(ans.Count == n) { break; }
                }
            }

            //if (isprime[ans.Sum()]){
            //    Console.WriteLine("wa");
            //}

            string sz = "";
            for(int i=0;i<ans.Count;++i)
            {
                if( i != 0) { sz += " "; }
                sz += ans[i];
            }
            Console.WriteLine(sz);
        }

        static bool[] eratos(int n)
        {
            bool[] isprime = new bool[n+1];
            for(int i = 0; i < isprime.Length; ++i) { isprime[i] = true; }

            isprime[0] = isprime[1] = false;

            int end =(int) Math.Ceiling( Math.Sqrt(n));
            for(int i=2;i<=end;++i)
            {
                if(isprime[i])
                {
                    int j = i + i;
                    while(j <= n)
                    {
                        isprime[j] = false;
                        j = j + i;
                    }
                }
            }
            return isprime;
        }
    }
}