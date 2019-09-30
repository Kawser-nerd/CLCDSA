using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace abc_016_C
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
            bool[,] friends = new bool[n[0], n[0]];
            for(int i = 0; i < n[1]; i++)
            {
                int[] u = Console.ReadLine().Split().Select(int.Parse).ToArray();
                friends[u[0] - 1, u[1] - 1]=true;
                friends[u[1] - 1, u[0] - 1] = true;
            }
            bool[,] friends_friends = new bool[n[0], n[0]];

            for (int i = 0; i < n[0]; i++)
            {
                for (int j = 0; j < n[0]; j++)
                {
                    if (i == j) { continue; }
                    if (friends[i, j]) { continue; }

                    for (int k = 0; k < n[0]; k++)
                    {
                        if (friends[i, k] && friends[j, k])
                        {
                            friends_friends[i, j] = true;
                            friends_friends[j, i] = true;
                            break;
                        }
                    }    
                    
                }
            }
            int[] sum = new int[n[0]];
            for(int i = 0; i < n[0]; i++)
            {
                for(int j = 0; j <= i; j++)
                {
                    if (friends_friends[i, j]) { sum[i]++;sum[j]++; }
                }
            }
            foreach(int j in sum)
            {
                Console.WriteLine(j);
            }
            Console.ReadLine();
        }
    }
}