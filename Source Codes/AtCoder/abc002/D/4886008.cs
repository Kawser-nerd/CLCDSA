using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        //
        static void Main(string[] args)
        {
            string[] Input = Console.ReadLine().Split(' ');
            int N = int.Parse(Input[0]);
            int M = int.Parse(Input[1]);

            bool[,] hyou = new bool[N, N];

            for (int i = 0; i < M; i++)
            {
                string[] tmpRela = Console.ReadLine().Split(' ');
                int x = int.Parse(tmpRela[0]);
                int y = int.Parse(tmpRela[1]);

                hyou[(x - 1), (y - 1)] = true;
                hyou[(y - 1), (x - 1)] = true;
            }

            int MaxNinzu = 0;

            for (int i = 0; i < (1 << N); i++)
            {
                List<int> binary = new List<int>();

                for (int j = 0; j < N; j++)
                {
                    if ((i >> j & 1) == 1)
                    {
                        binary.Add(j);
                    }
                }

                bool tmpFlag = true;

                foreach (int tmpA in binary)
                {
                    foreach (int tmpB in binary)
                    {
                        if (tmpA == tmpB) { continue; }

                        if (!hyou[tmpA, tmpB])
                        { tmpFlag = false; }
                    }
                }

                if (tmpFlag)
                { MaxNinzu = Math.Max(MaxNinzu, binary.Count); }
            }

            Console.WriteLine(MaxNinzu);
        }

    }

}