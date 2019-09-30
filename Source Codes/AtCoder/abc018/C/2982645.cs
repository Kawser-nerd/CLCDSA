using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_018
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string[] input = Console.ReadLine().Split(' ');
            int r = int.Parse(input[0]);
            int c = int.Parse(input[1]);
            int k = int.Parse(input[2]);
            var isWhite = new bool[r, c];
            for (int i = 0; i < r; i++)
            {
                string str = Console.ReadLine();
                for (int j = 0; j < c; j++)
                {
                    isWhite[i, j] = str[j] == 'o';
                }
            }

            var upWhiteCnt = new int[r, c];
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (isWhite[i, j])
                    {
                        if (i == 0)
                        {
                            upWhiteCnt[i, j] = 1;
                        }
                        else
                        {
                            upWhiteCnt[i, j] = upWhiteCnt[i - 1, j] + 1;
                        }
                    }
                    else
                    {
                        upWhiteCnt[i, j] = 0;
                    }
                }
            }
            var downWhiteCnt = new int[r, c];
            for (int i = r - 1; i >= 0; i--)
            {
                for (int j = 0; j < c; j++)
                {
                    if (isWhite[i, j])
                    {
                        if (i == r - 1)
                        {
                            downWhiteCnt[i, j] = 1;
                        }
                        else
                        {
                            downWhiteCnt[i, j] = downWhiteCnt[i + 1, j] + 1;
                        }
                    }
                    else
                    {
                        downWhiteCnt[i, j] = 0;
                    }
                }
            }

            /*for (int i = 0; i < r; i++)
            {
                string s = "";
                for (int j = 0; j < c; j++)
                {
                    s += upWhiteCnt[i, j].ToString() + "/" + downWhiteCnt[i, j].ToString();
                    s += " ";
                }
                Console.WriteLine(s);
            }*/

            int cnt = 0;
            for (int y = k - 1; y <= r - k; y++)
            {
                for (int x = k - 1; x <= c - k; x++)
                {
                    bool ok = true;
                    for (int i = -k + 1; i <= k - 1; i++)
                    {
                        ok &= upWhiteCnt[y, x + i] >= k - Math.Abs(i)
                            && downWhiteCnt[y, x + i] >= k - Math.Abs(i);
                    }
                    if (ok)
                    {
                        cnt++;
                        //Console.WriteLine(x.ToString() + "," + y.ToString());
                    }
                }
            }

            Console.WriteLine(cnt);
        }
    }
}