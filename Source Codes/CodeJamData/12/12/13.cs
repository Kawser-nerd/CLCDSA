using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string filename = "B-large";
            //string filename = "B-small-attempt0";
            //string filename = "test";

            string[] inLine = File.ReadAllLines(filename + ".in");
            int T = Convert.ToInt32(inLine[0]);
            string[] outLine = new String[T];
            int currentline = 1;

            for (int t = 1; t <= T; t++)
            {
                int result = 0;

                int N = Convert.ToInt32(inLine[currentline++]);
                int[] a = new int[N];
                int[] b = new int[N];


                for (int n = 0; n < N; n++)
                {
                    string[] tmp = inLine[currentline++].Split(' ');
                    a[n] = Convert.ToInt32(tmp[0]);
                    b[n] = Convert.ToInt32(tmp[1]);
                }

                int star = 0;
                Boolean[] level1 = new Boolean[N]; // finished = true
                Boolean[] level2 = new Boolean[N];
                for (int m = 1; m <= 2 * N; m++)
                {

                    int n = 0;
                    for (; n < N; n++)
                    {
                        if (!level2[n] && b[n] <= star)
                        {
                            if (level1[n])
                            {
                                level2[n] = true;
                                star += 1;
                                break;
                            }
                            else
                            {
                                level1[n] = true;
                                level2[n] = true;
                                star += 2;
                                break;
                            }
                        }
                    }
                    if (n < N)
                    {
                    }
                    else
                    {

                        int i = -1;

                        for (n = 0; n < N; n++)
                        {
                            if (!level1[n] && a[n] <= star && (i == -1 || b[i] < b[n]))
                            {
                                i = n;
                            }
                        }

                        if (i == -1)
                        {
                            result = -1;
                            break;
                        }
                        else
                        {
                            level1[i] = true;
                            star += 1;

                        }
                    }
                    if (star == 2 * N)
                    {
                        result = m;
                        break;
                    }
                }
                if (result < 0)
                {
                    outLine[t - 1] = "Case #" + t.ToString() + ": Too Bad";
                }
                else
                {
                    outLine[t - 1] = "Case #" + t.ToString() + ": " + result.ToString();

                }
            }

            File.WriteAllLines(filename + ".out", outLine);

        }
    }
}
