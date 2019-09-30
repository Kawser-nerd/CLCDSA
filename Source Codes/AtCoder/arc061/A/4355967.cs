using System;
using System.Collections.Generic;
using System.Linq;

namespace ARC061C
{
    class MainClass
    {
        static string[] s;

        public static void Main(string[] args)
        {
            s = Console.ReadLine().Split().ToArray();
            int slen = s[0].Length;
            int n = slen - 1;
            long ans = 0;

            List<long> slstorg = new List<long>();
            for(int i = 0; i < slen; i++)
            {
                slstorg.Add(long.Parse(s[0][i].ToString()));
            }

            //slstorg.ForEach(Console.WriteLine);


            // {0, 1, ..., n-1} ?????????
            for (int bit = 0; bit < (1 << n); ++bit)
            {


                List<long> slst = new List<long>(slstorg);
                /* bit ????????????? */
                for (int i = 0; i < n; i++)
                {
                    //connect
                    if((bit & (1 << i)) > 0)
                    {
                       // Console.WriteLine("connect bit: " + Convert.ToString(bit, 2) + " i: " + i);
                        //string tmp = s[0][i - s[0].Length].ToString() + s[0][i - s[0].Length].ToString();
                        string tmp = slst[i].ToString()+ slst[i+1].ToString();
                        slst[i] = 0;
                        slst[i + 1] = long.Parse(tmp);
                    }
                }

               // Console.Write("bit : " + Convert.ToString(bit, 2) + " slst: ");
               // slst.ForEach(Console.WriteLine);


                //Console.WriteLine(bit);

                ans += slst.Sum();
            }

            Console.WriteLine(ans);

        }
    }
}