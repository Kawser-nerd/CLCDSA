using System;
using System.Collections.Generic;
using System.Text;

namespace SavingtheUniverse
{
    class Program
    {
        static void Main(string[] args)
        {
            string input;
            int N,S,Q;
            input = Console.ReadLine();
            N = int.Parse(input);
            for (int n = 0; n < N; n++)
            {
                input = Console.ReadLine();
                S = int.Parse(input);
                string[] searchEngines = new string[S];
                for (int s = 0; s < S; s++)
                {
                    input = Console.ReadLine();
                    searchEngines[s] = input;
                }
                input = Console.ReadLine();
                Q = int.Parse(input);
                string[] queries = new string[Q];
                for (int q = 0; q < Q; q++)
                {
                    input = Console.ReadLine();
                    queries[q] = input;
                }
                int ans = 0;
                bool[] engine = new bool[S];
                for (int l = 0; l < S; l++)
                {
                    engine[l] = false;
                }
                int count = S;
                for (int i = 0; i < Q; i++)
                {
                    for (int j = 0; j < S; j++)
                    {
                        if (searchEngines[j] == queries[i])
                        {
                            if (engine[j] == false)
                            {
                                engine[j] = true;
                                count--;
                            }
                            if (count == 0)//We considered all engines.
                            {
                                ans++;
                                for (int k = 0; k < S; k++)
                                {
                                    engine[k] = false;
                                }
                                engine[j] = true;
                                count = S - 1;
                            }
                            break;
                        }
                    }
                }
                int temp = n + 1;
                Console.WriteLine("Case #" + temp.ToString() + ": " + ans.ToString());
            }
        }
    }
}
