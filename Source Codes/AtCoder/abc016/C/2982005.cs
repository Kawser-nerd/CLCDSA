using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_016
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int n = int.Parse(input[0]);
            int m = int.Parse(input[1]);

            var friendTable = new bool[n, n];
            var friendCnt = new int[n];
            for (int i = 0; i < m; i++)
            {
                input = Console.ReadLine().Split(' ');
                int a = int.Parse(input[0]) - 1;
                int b = int.Parse(input[1]) - 1;
                friendTable[a, b] = true;
                friendTable[b, a] = true;
                friendCnt[a]++;
                friendCnt[b]++;
            }

            /*for(int i = 0; i < n; i++)
            {
                string s = "";
                for (int j = 0; j < n; j++)
                {
                    if (i == j) s += "?";
                    else if (friendTable[i, j]) s += "?";
                    else s += "×";
                    s += " ";
                }
                Console.WriteLine(s);
            }*/

            for(int i = 0; i < n; i++)
            {
                int friends = 0;
                var indirectFriend = new bool[n];
                for(int j = 0; j < n; j++)
                {
                    if (i == j || !friendTable[i, j]) continue;

                    for (int k = 0; k < n; k++)
                    {
                        if (friendTable[j, k] && i != k && !friendTable[i, k])
                        {
                            indirectFriend[k] = true;
                        }
                    }
                }

                for(int j = 0; j < n; j++)
                {
                    if (indirectFriend[j]) friends++;
                }

                Console.WriteLine(friends);
            }
        }
    }
}