using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AllSearch
{
    class ARC_A29_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] times = new int[n];
            for (int i = 0; i < n; i++)
            {
                times[i] = int.Parse(Console.ReadLine());
            }
            int min = 200;
            int allPat = (int)Math.Pow(2, n);
            for (int i = 0; i < allPat; i++)
            {
                int time1 = 0, time2 = 0;
                for(int j = 0; j < n; j++)
                {
                    if(((i>>j)&1)==1)
                    {
                        time1 += times[j];
                    }
                    else
                    {
                        time2 += times[j];
                    }
                }

                int time = time1 > time2 ? time1 : time2;
                if (time < min)
                {
                    min = time;
                }
            }
            Console.WriteLine(min);
        }
    }
}