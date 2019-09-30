using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            int C = int.Parse(Console.ReadLine());

            for (int i = 1; i <= C; i++)
            {
                int N = int.Parse(Console.ReadLine());
                int M = int.Parse(Console.ReadLine());
                int[] T = new int[M];
                int[,,] table = new int[M, 3000,2];
                int[] OUT = new int[N];
                for (int j = 0; j < N; j++) OUT[j] = -1;
                for (int j = 0; j < M; j++)
                {
                    string[] s = Console.ReadLine().Split(' ');
                    T[j] = int.Parse(s[0]);
                    for (int k = 0; k < T[j]; k++)
                    {
                        table[j, k, 0] = int.Parse(s[k * 2 + 1])-1;
                        table[j, k, 1] = int.Parse(s[(k+1) * 2]);
                    }
                }
                bool changed = true;
                bool impossible = false;
                while (changed)
                {
                    changed = false;
                    for (int j = 0; j < M; j++)
                    {
                        bool unmalted = false;
                        bool malted = false;
                        int id_malted = -1;
                        for (int k = 0; k < T[j]; k++)
                        {
                            if (table[j, k, 1] == 0)
                            {
                                if(OUT[table[j, k, 0]]<1)
                                {
                                    unmalted = true;
                                }
                            }
                            else
                            {
                                id_malted = k;
                                if (OUT[table[j, k, 0]] != 0)
                                {
                                    malted = true;
                                }
                                else malted = false;
                            }
                        }
                        if (unmalted) continue;
                        else if (malted)
                        {
                            if (OUT[table[j, id_malted, 0]] == -1)
                            {
                                changed = true;
                                OUT[table[j, id_malted, 0]] = 1;
                            }
                            continue;
                        }
                        else
                        {
                            impossible = true;
                            break;
                        }
                    }
                    if (impossible) break;
                }
                if (impossible)
                {
                    Console.WriteLine("Case #" + i.ToString() + ": IMPOSSIBLE");
                }
                else
                {
                    for (int j = 0; j < N; j++) if (OUT[j] == -1) OUT[j]=0;
                    Console.Write("Case #" + i.ToString() + ": ");
                    for (int j = 0; j < N; j++) Console.Write(OUT[j].ToString() + " ");
                    Console.WriteLine();
                }
            }
        }
    }
}
