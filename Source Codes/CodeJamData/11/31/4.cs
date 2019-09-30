using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace TaskA
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            var reader = new StreamReader("a.in");
            var writer = new StreamWriter("a.out");

            var countTest = Int32.Parse(reader.ReadLine());

            for (var iTest = 0; iTest < countTest; iTest++)
            {
                var line = reader.ReadLine().Split(' ');
                var r = Int32.Parse(line[0]);
                var c = Int32.Parse(line[1]);

                var s = new char[r][];

                for (var i = 0; i < r; i++)
                {
                    s[i] = reader.ReadLine().ToArray();
                }

                var flag = true;

                for (var ri = 0; ri < r; ri++)
                {
                    for (var ci = 0; ci < c; ci++)
                    {
                        if (s[ri][ci] == '#')
                        {
                            if ((ci + 1 < c) && (s[ri][ci + 1] == '#') && (ri + 1 < r) && (s[ri + 1][ci] == '#') &&
                                (s[ri + 1][ci + 1] == '#'))
                            {
                                s[ri][ci] = '/';
                                s[ri][ci + 1] = '\\';
                                s[ri + 1][ci] = '\\';
                                s[ri + 1][ci + 1] = '/';
                            }
                            else
                            {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (!flag)
                    {
                        break;
                    }
                }


                writer.WriteLine("Case #{0}:", iTest + 1);
                if (flag)
                {
                    for (var ri = 0; ri < r; ri++)
                    {
                        for (var ci = 0; ci < c; ci++)
                        {
                            writer.Write(s[ri][ci]);
                        }
                        writer.WriteLine();
                    }
                }
                else
                {
                    writer.WriteLine("Impossible");
                }
            }


            reader.Close();
            writer.Close();
        }
    }
}