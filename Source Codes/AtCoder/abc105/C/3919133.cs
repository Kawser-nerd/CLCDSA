using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC105C
{
    static class MainClass
    {

        public static void Main(string[] args)
        {


         
            int N = int.Parse(Console.ReadLine());

            if (N == 0)
            {
                Console.WriteLine("0");
                return;
            }
            int diff = N;
            var anslist = new List<int>();
            int anstmp = 0;
            while (diff != 0)
            {
                anstmp = GetInitial(diff);
                anslist.Add(anstmp);
                diff = diff - (int)Math.Pow(-2, anstmp);
                //Console.WriteLine("diff: " + diff.ToString() + "anstmp: " + anstmp.ToString());
            }

            string ans = "";
            int tmp = anslist.First();
            foreach(int item in anslist)
            {
                for(int i=0;i<tmp - item-1; i++)
                {
                    ans += "0";
                }
                ans += "1";
                tmp = item;
            }
            if(tmp > 0)
            {
                for(int i = 0; i < tmp; i++)
                {
                    ans += "0";
                }
            }
            Console.WriteLine(ans);


        }

        public static int GetInitial(int a)
        {

            long tmp = 0;
            if (a <0) {
                for(int i = 0; i < -a; i++)
                {
                    tmp = tmp + (int)Math.Pow(-2, 2 * i + 1);
                    if (a >= tmp)
                    {
                        return 2 * i + 1;
                    }
                }
            }else{
                for (int i = 0; i < a; i++)
                {
                    tmp = tmp + (int)Math.Pow(-2, 2 * i);
                    if (a <= tmp)
                    {
                        return 2 * i;
                    }
                }
            }

            return 0;
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