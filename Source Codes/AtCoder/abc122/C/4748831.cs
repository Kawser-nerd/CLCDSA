using System;

namespace ConsoleApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var strs = str.Split(' ');
            var N = int.Parse(strs[0]);
            var Q = int.Parse(strs[1]);

            var S = Console.ReadLine();

            var ls = new int[Q];
            var rs = new int[Q];
            for (int i = 0; i < Q; i++)
            {
                str = Console.ReadLine();
                strs = str.Split(' ');
                ls[i] = int.Parse(strs[0]);
                rs[i] = int.Parse(strs[1]);
            }

            var AC = new int[N + 1];
            for (int i = 0; i < N - 1; i++)
            {
                if (S[i] == 'A')
                {
                    if (S[i + 1] == 'C')
                    {
                        AC[i + 1] = AC[i] + 1;
                        i++;
                        AC[i + 1] = AC[i];
                    }
                    else
                    {
                        AC[i + 1] = AC[i];
                    }
                }
                else
                {
                    AC[i + 1] = AC[i];
                }
            }
            AC[N] = AC[N - 1];
            
            for (int i = 0; i < Q; i++)
            {
                Console.WriteLine(AC[rs[i] - 1] - AC[ls[i] - 1]);
            }
        }
    }
}