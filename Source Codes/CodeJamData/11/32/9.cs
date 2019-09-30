using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2011.Round1C.B
{
    class Program
    {
        static void Main(string[] args)
        {
            string FILENAME = "B-large";

            using (FileStream fin = File.OpenRead("D:/" + FILENAME + ".in"))
            {
                StreamReader reader = new StreamReader(fin);
                StringBuilder builder = new StringBuilder();

                int cases = int.Parse(reader.ReadLine());

                

                for (int c = 1; c <= cases; c++)
                {
                    long[] vals = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => long.Parse(s)).ToArray();

                    List<int> t = new List<int>();
                    for (int i = 0; i < 1000000; i++)
                    {
                        t.Add(i % 23784);
                    }

                    List<long> distances = new List<long>();
                    for (int i = 0; i < vals[2]; i++)
                    {
                        long dist = vals[4 + i % vals[3]];
                        distances.Add(dist);
                    }

                    long leftToBuild = vals[1];
                    long answ = 0;

                    long sum = vals.ToList().GetRange(4, vals.Length - 4).Sum();
                    long entires = Math.Min(leftToBuild / (sum * 2), vals[2] / vals[3]);

                    answ = entires * sum * 2;
                    leftToBuild -= entires * sum * 2;
                    distances.RemoveRange(0, (int)vals[3] * (int)entires);


                    while (true)
                    {
                        if (!distances.Any()) break;
                        if (leftToBuild >= 2 * distances[0])
                        {
                            leftToBuild -= 2 * distances[0];
                            answ += 2 * distances[0];
                            distances.RemoveAt(0);
                        }
                        else
                        {
                            distances[0] -= leftToBuild / 2;
                            answ += leftToBuild;
                            break;
                        }
                    }

                    distances = distances.OrderByDescending(a => a).ToList();

                    answ += distances.GetRange(0, (int)Math.Min(distances.Count, vals[0])).Sum();

                    if (vals[0] < distances.Count)
                    {
                        answ += distances.GetRange((int)vals[0],(int)(distances.Count - vals[0])).Sum() * 2;
                    }

                    Console.WriteLine(String.Format("Case #{0}: {1}", c, answ));
                    builder.AppendLine(String.Format("Case #{0}: {1}", c, answ));
                }

                using (FileStream fout = File.OpenWrite("D:/" + FILENAME + ".out"))
                {
                    StreamWriter writer = new StreamWriter(fout);
                    writer.Write(builder.ToString());
                    writer.Flush();
                }

                Console.WriteLine("Done.");
            }
        }
    }
}
