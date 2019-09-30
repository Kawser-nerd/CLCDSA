using System;
using System.Collections.Generic;

namespace codejam2014
{

    public class problema{
        public string[] data;
        int n ;



        public string solve()
        {
            n = data.Length;

            int total = 0;
            while(data[0].Length > 0)
            {
                char c = data[0][0];
                int [] vec = new int[n];
                int min = 100000;
                int max = 0;

                for(int i = 0; i<n; i++)
                {
                    int count = 0;

                    while(data[i].Length > 0 && data[i][0] == c)
                    {
                        count++;
                        data[i] = data[i].Remove(0, 1);
                    }

                    vec[i] = count;
                    if (count < min ) min =count;
                    if (count > max) max = count;
                }

                int y = max;

                if (min == 0)
                    return "Fegla Won";

                for(int j = min; j<=max; j++)
                {
                    int x = 0;

                    for(int i = 0; i<n; i++)
                    {
                        x += Math.Abs(vec[i] - j);
                    }

                    if (x < y)
                        y = x;
                }
                total += y;
            }

            for(int i = 0; i<n; i++)
                if (data[i].Length > 0) return "Fegla Won";

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
                int n = int.Parse(r.ReadLine());

                string[] data = new string[n];
                for(int i = 0; i<n; i++)
                    data[i] = r.ReadLine();

                problema p = new problema();
                p.data = data;

                string ret = p.solve();
                Console.WriteLine("Case #{0}: {1}", c, ret);
          
            }

            r.Close();

        }
    }
}

