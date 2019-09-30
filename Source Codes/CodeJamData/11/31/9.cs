using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Google.CodeJam2011.Round1B.A
{
    class Program
    {
        static void Main(string[] args)
        {
            string FILENAME = "A-large";

            using (FileStream fin = File.OpenRead("D:/" + FILENAME + ".in"))
            {
                StreamReader reader = new StreamReader(fin);
                StringBuilder builder = new StringBuilder();

                int cases = int.Parse(reader.ReadLine());

                for (int c = 1; c <= cases; c++)
                {
                    int[] sizes = reader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => int.Parse(s)).ToArray();

                    List<char[]> colors = new List<char[]>();
                    for (int i = 0; i < sizes[0]; i++)
                    {
                        colors.Add(reader.ReadLine().ToCharArray());
                    }

                    bool failed = false;
                    for (int i = 0; i < sizes[0] - 1; i++)
                    {
                        for (int j = 0; j < sizes[1] - 1; j++)
                        {
                            if (colors[i][j] == '#')
                            {
                                if (colors[i][j + 1] == '#' && colors[i + 1][j] == '#' && colors[i + 1][j + 1] == '#')
                                {
                                    colors[i][j] = colors[i + 1][j + 1] = '/';
                                    colors[i + 1][j] = colors[i][j + 1] = '\\';
                                }
                                else
                                {
                                    failed = true;
                                    break;
                                }
                            }
                        }
                        if (failed) break;
                    }

                    if (!failed)
                    {
                        failed = colors.Any(r => r.Any(v => v == '#'));
                    }

                    if (failed)
                    {
                        builder.AppendLine(String.Format("Case #{0}: \nImpossible", c));
                    }
                    else
                    {
                        builder.AppendLine(String.Format("Case #{0}:", c));
                        colors.ForEach(row =>
                        {
                            row.ToList().ForEach(v =>
                            {
                                builder.Append(v);
                            });
                            builder.AppendLine();
                        });
                    }

                    
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
