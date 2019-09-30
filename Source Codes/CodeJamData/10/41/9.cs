using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;

namespace Round2A
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("F:\\in2.in");
            StreamWriter sw = new StreamWriter("F:\\out2.out");
            sw.AutoFlush = true;
            int n = int.Parse(sr.ReadLine());
            Console.WriteLine(n);
            for (int i = 0; i < n; i++)
            {
                sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
                Console.WriteLine(i);
            }
            sw.Close();
            sr.Close();
            Console.WriteLine("Finished");
            Console.ReadLine();
        }

        static string Solution(StreamReader sr)
        {
            int k = int.Parse(sr.ReadLine());
            string[][] H = new string[k * 2 - 1][];
            for (int i = 0; i < k * 2 - 1; i++)
            {
                H[i] = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            }
            int[,] A = new int[2 * k - 1, 2 * k - 1];
            for (int i = 0; i < 2 * k - 1; i++)
            {
                for (int j = 0; j < 2 * k - 1; j++)
                {
                    A[i, j] = -1;
                }
            }
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < H[i].Length; j++)
                {
                    A[i, k - i + j * 2 - 1] = H[i][j][0] - '0';
                }
            }
            for (int i = k; i < 2 * k - 1; i++)
            {
                for (int j = 0; j < H[i].Length; j++)
                {
                    A[i, i - k + j * 2 + 1] = H[i][j][0] - '0';
                }
            }
            /*  for (int i = 0; i < 2 * k - 1; i++)
              {
                  for (int j = 0; j < 2 * k - 1; j++)
                  {
                      Console.Write((A[i,j]==-1)?" ":A[i,j].ToString());
                  }
                  Console.WriteLine();
              }*/
            int n = k;
            while (true)
            {
                int g = n - k;
                bool c = false;
                for (int i = -g; i <= g; i++)
                {
                    for (int j = Math.Abs(i) - g; j <= g - Math.Abs(i); j++)
                    {
                        if ((((i + j) % 2) + 2) % 2 == (n - k) % 2)
                        {
                            bool d = true;
                            for (int a = -k + 1; a <= k - 1&&d; a++)
                            {
                                for (int b = -k + 1; b <= k - 1; b++)
                                {
                                    int x = a + i;
                                    int y = b + j;
                                    if (-x - i > -k && -x - i < k)
                                        if (A[a + k - 1, b + k - 1] != A[-x - i + k - 1, b + k - 1])
                                        {
                                            if (A[a + k - 1, b + k - 1] != -1 && A[-x - i + k - 1, b + k - 1] != -1)
                                            {
                                                d = false;
                                                break;
                                            }
                                        }
                                    if (-y - j > -k && -y - j < k)
                                        if (A[a + k - 1, b + k - 1] != A[a + k - 1, -y - j + k - 1])
                                        {
                                            if (A[a + k - 1, b + k - 1] != -1 && A[a + k - 1, -y - j + k - 1] != -1)
                                            {
                                                d = false;
                                                break;
                                            }
                                        }

                                }
                            }
                            if (d)
                                c = true;
                        }
                    }
                }

                if (c)
                    return (n + n * (n - 1) - k - k * (k - 1)).ToString();

                n++;
            }
        }
    }
}
