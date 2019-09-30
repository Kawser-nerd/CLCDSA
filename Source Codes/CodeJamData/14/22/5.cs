
using System;
using System.Collections.Generic;

namespace codejam2014
{

    public class problemb{
       
        public string solve(int a, int b, int k)
        {

            long total = 0;

            for(int i = 0; i<a; i++)
                for(int j = 0; j<b; j++)
                {
                    int c = i & j;

                    if (c < k) total++;
                }
            return string.Format("{0}", total);
        }
    }

    class MainClass
    {


        public static void Main(string[] args)
        {

            System.IO.TextReader r = new System.IO.StreamReader(args[0]);

            int t = int.Parse(r.ReadLine());

            for(int c = 1; c<=t; c++)
            {
                problemb p = new problemb();
            

                string[] x = r.ReadLine().Split(' ');
                int a = int.Parse(x[0]);
                int b = int.Parse(x[1]);
                int k = int.Parse(x[2]);

                string ret = p.solve(a,b,k);
                Console.WriteLine("Case #{0}: {1}", c, ret);

            }

            r.Close();

        }
    }
}

