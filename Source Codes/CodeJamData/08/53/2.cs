using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2008
{
    class Program
    {
        static int bits(int bit)
        {
            int count = 0;
            while (bit != 0)
            {
                bit &= bit - 1;
                count++;
            }
            return count;
        }
     
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("C-small-attempt0.in");
            string output = "";
            int lineAt = 0;
            int testCases = int.Parse(input[lineAt++]);
            for (int i = 0; i < testCases; i++)
            {
                string[] line = input[lineAt++].Split(' ');
                int rows = int.Parse(line[0]);
                int cols = int.Parse(line[1]);
                string[] classroom = new string[rows];
                for (int j = 0; j < rows; j++)
                {
                    classroom[j] = input[lineAt++];
                }
                int max = (1 << cols) - 1;
                int[,] dp = new int[rows, 1 << cols];
                for (int k = 0; k < rows; k++)
                {
                    int bad = 0;
                    for (int j = 0; j < cols; j++)
                    {
                        if (classroom[k][j] == 'x') bad |= (1 << j);
                    }
                    for (int j = 0; j < (1 << cols); j++)
                    {
                        if ((j & bad) == 0 && (j & (j<<1)) == 0 && (j & (j >> 1)) == 0)
                        {
                            if (k == 0)
                            {
                                dp[k, j] = bits(j);
                            }
                            else
                            {
                                int best = 0;
                                int badb = ((j << 1) | (j >> 1)) & max;

                                for (int q = 0; q < (1 << cols); q++)
                                {
                                    if ((q & badb) == 0)
                                    {
                                        best = Math.Max(best, dp[k - 1, q]);
                                    }
                                }
                                dp[k, j] = best + bits(j);
                            }
                        }
                        else
                        {
                            dp[k, j] = -999999999;
                        }
                    }
                }
                int num = 0;
                for (int j = 0; j < (1 << cols); j++)
                {
                    num = Math.Max(dp[rows - 1, j], num);
                }
                    
                output += "Case #" + (i + 1) + ": " + num + Environment.NewLine;
            }
            File.WriteAllText("output.txt", output);
            Console.WriteLine(output);
        }
        static bool rock(int r, int c, int[] rr, int[] rc)
        {
            for (int i = 0; i < rr.Length; i++)
            {
                if (rr[i] == r && rc[i] == c) return true;
            }
            return false;
        }
    }
}
