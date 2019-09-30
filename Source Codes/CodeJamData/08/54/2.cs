using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace GoogleCodeJam2008
{
    class Program
    {
       
        static void Main(string[] args)
        {
            string[] input = File.ReadAllLines("D-small-0.in");
            string output = "";
            int lineAt = 0;
            int testCases = int.Parse(input[lineAt++]);
            for (int i = 0; i < testCases; i++)
            {
                string[] line = input[lineAt++].Split(' ');
                int h = int.Parse(line[0]);
                int w = int.Parse(line[1]);
                int r = int.Parse(line[2]);
                
                int[] rc = new int[r];
                int[] rr = new int[r];
                for (int j = 0; j < r; j++)
                {
                    line = input[lineAt++].Split(' ');
                    rr[j] = int.Parse(line[0])-1;
                    rc[j] = int.Parse(line[1])-1;
                }
                int num;
                if (h == 1)
                {
                    num = w == 1 ? 1 : 0;
                }
                else if (w == 1)
                {
                    num = 0;
                }
                else if (w == 2)
                {
                    num = h == 3 ? 1 : 0;
                }
                else if (h == 2)
                {
                    num = w == 3 ? 1 : 0;
                }
                else
                {
                    int[] count1 = new int[w];
                    int[] count2 = new int[w];

                    count1[0] = 1;
                    if (!rock(1, 2, rr, rc))
                    {
                        count2[2] = 1;
                    }

                    for (int j = 2; j < h; j++)
                    {
                        int[] count3 = new int[w];
                        if (!rock(j, 1, rr, rc))
                        {
                            count3[1] = count1[0];
                        }
                        for (int k = 2; k < w; k++)
                        {
                            if (!rock(j, k, rr, rc))
                            {
                                count3[k] += count2[k - 2] + count1[k - 1];
                                count3[k] %= 10007;
                            }
                        }
                        count1 = count2;
                        count2 = count3;
                    }
                    num = count2[w - 1];
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
