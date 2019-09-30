using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Globalization.NumberFormatInfo provider = new System.Globalization.NumberFormatInfo() { NumberDecimalSeparator = "." };
            int t;
            string[] lines = System.IO.File.ReadAllLines("input.txt");
            t = Convert.ToInt32(lines[0]);
            string[] answers = new string[t];
            Parallel.For(0, t, (num) =>
            {
                string[] parts = lines[num + 1].Split(' ');

                int r = Convert.ToInt32(parts[0]);
                int c = Convert.ToInt32(parts[1]);
                int m = Convert.ToInt32(parts[2]);

                m = r * c - m;

                answers[num] = string.Format("Case #{0}:\nImpossible", num + 1);
                for (int i = 1; i <= r; ++i)
                {
                    for (int j = 1; j <= c; ++j)
                    {
                        for (int k = 0; k <= i; ++k)
                        {
                            for (int l = 0; l <= j; ++l)
                            {
                                if (k == 1 || l == 1)
                                {
                                    continue;
                                }
                                if (j == c && k != 0)
                                {
                                    continue;
                                }
                                if (i == r && l != 0)
                                {
                                    continue;
                                }
                                if (i == 1 && i != r && m != 1)
                                {
                                    continue;
                                }
                                if (j == 1 && j != c && m != 1)
                                {
                                    continue;
                                }
                                if (i * j + k + l == m)
                                {
                                    char[,] map = new char[r, c];
                                    for (int _ = 0; _ < r; ++_)
                                    {
                                        for (int __ = 0; __ < c; ++__)
                                        {
                                            map[_, __] = (_ >= i || __ >= j) ? '*' : '.';
                                        }
                                    }
                                    for (int _ = 0; _ < k; ++_)
                                    {
                                        map[_, j] = '.';
                                    }
                                    for (int _ = 0; _ < l; ++_)
                                    {
                                        map[i, _] = '.';
                                    }
                                    map[0, 0] = 'c';
                                    answers[num] = string.Format("Case #{0}:", num + 1);
                                    for (int _ = 0; _ < r; ++_)
                                    {
                                        answers[num] += "\n";
                                        for (int __ = 0; __ < c; ++__)
                                        {
                                            answers[num] += map[_, __];
                                        }
                                    }
                                    return;
                                }
                            }
                        }
                    }
                }
            });
            System.IO.File.WriteAllLines("output.txt", answers);
        }
    }
}
