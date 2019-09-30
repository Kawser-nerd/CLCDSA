using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC104C
{
    static class MainClass
    {

        public static void Main(string[] args)
        {


            string[] input1 = Console.ReadLine().Split(' ');
            int D = int.Parse(input1[0]);
            int G = int.Parse(input1[1]);
            var plst = new List<int>();
            var clst = new List<int>();
            var RestDlst = new List<int>();
            var Dmemolst = new List<int>();
            int p = 0;
            int c = 0;
            for (int i = 0; i < D; i++) {
                string[] input2 = Console.ReadLine().Split(' ');
                p = int.Parse(input2[0]);
                c = int.Parse(input2[1]);
                plst.Add(p);
                clst.Add(c);
                RestDlst.Add(i+1);
                Dmemolst.Add(p * (i + 1) * 100 + c);
           }
            int ans = 1000000000;
            
            for (int mask = 0; mask < (1 << D); mask++)
            {

                int pt = 0, restmax = -1,num=0;
                
                //??0101...??pt???
                for(int i = 0; i < D; i++)
                {
                    //Console.WriteLine("mask: " + mask.ToString() + " maskbit: " + (mask>>1).ToString());
                    if (((mask >> i) & 1)==1)
                    {
                        pt += 100 * (i + 1) * plst[i] + clst[i];
                        num += plst[i];
                    }
                    else
                    {
                        restmax = i;
                    }
                }
                //G??????????restmax????????
                if (pt < G)
                {
                    //restmax?1???????
                    int ptrmx = 100 * (restmax + 1);
                    int neednum = (G - pt + ptrmx - 1) / ptrmx;
                    //???????p[restmax]???????????0100...???
                    if(neednum > plst[restmax])
                    {
                        continue;
                    }
                    num += neednum;
                }
                ans = Math.Min(ans, num);
            }

            Console.WriteLine(ans);


            return;


        }


        public static int Dfs(int p, int D, List<int> plst, List<int> clst, List<int> RestDlst, int N, int G,List<int> Dmemolst)
        {

            if (p >= G)
            {
                return N;
            }
            if (Dmemolst[D - 1] + p < G)
            {
                p = p + Dmemolst[D - 1];
                N += plst[D - 1];
            }
            else {
                for (int i = 0; i < plst[D - 1]; i++)
                {
                    p = p + 100 * D;
                    N++;
                    if (p >= G) {
                        return N;
                    }
                }
                p += clst[D - 1];
            } 
            if (p >= G)
            {
                return N;
            }
            var anslst = new List<int>();
            foreach(int item in RestDlst)
            {
                var tmpRDlst = new List<int>(RestDlst);
                tmpRDlst.Remove(item);
                anslst.Add(Dfs(p, item, plst, clst, tmpRDlst, N, G,Dmemolst));
            }
            return anslst.Min();
        }



        public static long Gcd(long a, long b)
        {
            long tmp;
            // a<b???
            if (a >= b)
            {
                tmp = a;
                a = b;
                b = tmp;
            }

            if (a == 0)
            {
                return b;
            }

            tmp = a;
            a = b % a;
            b = tmp;
            return Gcd(a, b);

        }


        public static IEnumerable<long> PF(long n)
        {
            long i = 2;
            long tmp = n;

            while (i * i <= n) //?1
            {
                if (tmp % i == 0)
                {
                    tmp /= i;
                    yield return i;
                }
                else
                {
                    i++;
                }
            }
            if (tmp != 1) yield return tmp;//????????
        }




    }

}