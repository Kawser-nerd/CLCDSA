using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace program
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int q = int.Parse(input[1]);
            int[] ban = new int[n];

            //???
            for (int i = 0; i < q; i++)
            {
                string[] lr = Console.ReadLine().Split(' ');
                int start = int.Parse(lr[0]) - 1;
                int end = int.Parse(lr[1]);

                ban[start]++;
                if (end != n)
                {
                    ban[end]--;
                }
            }
            
            for (int i = 0; i < n; i++)
            {
                if (i != 0)
                {
                    ban[i] += ban[i - 1];
                }
                Console.Write((ban[i] % 2 ==1) ? "1" : "0");
            }


            Console.WriteLine();
        }
    }
}