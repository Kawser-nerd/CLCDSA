using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            List<int> Times = new List<int>();
            for (int i = 0; i < N; i++ )
            {
                Times.Add(int.Parse(Console.ReadLine()));
            }

            Times.Sort((a, b) => b - a);
            int Load1 = 0;
            int Load2 = 0;

            for (int i = 0; i < N; i++)
            {
                if (Load1 < Load2)
                { Load1 += Times[i]; continue; }

                Load2 += Times[i];
            }

            Console.WriteLine(Math.Max(Load1, Load2).ToString());
        }

    }
    
}