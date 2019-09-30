using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1CProblemC
{
    public class Program
    {
        static void Main(string[] args)
        {
            TextReader reader = new StreamReader("C-small-attempt4.in");
            string line = reader.ReadLine();
            TextWriter writer = new StreamWriter("out.in");

            int T = int.Parse(line.Trim());

            for (int i = 1; i <= T; i++)
            {
                line = reader.ReadLine();
                Int64 N = Int64.Parse(line.Split(' ')[0]);
                Int64 M = Int64.Parse(line.Split(' ')[1]);
                Int64 K = Int64.Parse(line.Split(' ')[2]);

                if (N <= 2 || M <= 2)
                {
                    writer.WriteLine("Case #" + i + ": " + K);
                }
                else if (K <= 4)
                {
                    writer.WriteLine("Case #" + i + ": " + K);
                }
                else
                {
                    if (K >= (N * M) - 4)
                    {
                        Int64 stones = (2 * N) + 2 * (M - 2);

                        Int64 offset = N * M - K;

                        stones -= offset;

                        writer.WriteLine("Case #" + i + ": " + stones);
                    }
                    else
                    {
                        //taking the smallest circle
                        Int64 x = 1;
                        Int64 y = 1;

                        while (true)
                        {
                            Int64 points = x * (y + 2) + y * 2;

                            if (points >= K)
                            {
                                //found it, count the stones
                                Int64 stones = 2 * x + 2 * y;
                                writer.WriteLine("Case #" + i + ": " + stones);
                                break;
                            }
                            else if (points + 1 >= K)
                            {
                                //only one more stone needed, put it in the corner
                                Int64 stones = 2 * x + 2 * y + 1;
                                writer.WriteLine("Case #" + i + ": " + stones);
                                break;
                            }
                            else if (points + 2 >= K)
                            {
                                //only two more stones needed, put two stones instead of one on the corner
                                Int64 stones = 2 * x + 2 * y + 1;
                                writer.WriteLine("Case #" + i + ": " + stones);
                                break;
                            }
                            else
                            {
                                //didn't find it, enlarge the circle
                                if (x + 2 < N)
                                {
                                    //x is possible to increase
                                    if (y + 2 < M)
                                    {
                                        //y is possible to increase
                                        if (x == y)
                                        {
                                            ++x;
                                        }
                                        else
                                        {
                                            ++y;
                                        }
                                    }
                                    else
                                    {
                                        //y is not possible to increase
                                        ++x;
                                    }
                                }
                                else
                                {
                                    //x is not possible to increase
                                    if (y + 2 < M)
                                    {
                                        //y is possible to increase
                                        ++y;
                                    }
                                }
                            }
                        }
                    }
                }

                writer.Flush();
            }
        }
    }
}
