using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Main
{
    class Program
    {
        static void Main(string[] arg)
        {
            int n = int.Parse(Console.ReadLine());
            int[] ta = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int[] hlist = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
            int t = ta[0];
            int a = ta[1];

            float nearest = Math.Abs(100000 - a);
            int answer = 0;

            for(int i = 0; i < n; i++)
            {
                float temp = t - (hlist[i] * 0.006f);
                if(nearest > Math.Abs(temp - a))
                {
                    nearest = Math.Abs(temp - a);

                    answer = i + 1;
                    if (Math.Abs(temp - a) == 0)
                    {
                        break;
                    }
                }


            }

            Console.WriteLine(answer);
            Console.ReadLine();

        }
    }
}