using System;
using System.IO;

namespace ProblemA
{
    class Program
    {
        static int Solve(string[] lines)
        {
            for (int i = 0; i < lines.Length; i++)
            {
                char[] line = lines[i].ToCharArray();
                for (int j = (lines.Length / 2 + i) % 2; j < line.Length; j += 2)
                {
                    if (line[j] == ' ')
                    {
                        line[j] = '*';
                    }
                }
                lines[i] = new String(line);
            }

            bool[,] horiz = new bool[lines.Length, lines[0].Length];
            for (int i = 0; i < lines.Length; i++)
            {
                for (int j = 0; j < lines[i].Length; j++)
                {
                    horiz[i, j] = true;
                    for (int k = 1; k < lines[i].Length; k++)
                    {
                        if (j - k >= 0 && j + k < lines[i].Length)
                        {
                            if (lines[i][j - k] != lines[i][j + k] && lines[i][j - k] != '*' && lines[i][j + k] != '*')
                            {
                                horiz[i, j] = false;
                                break;
                            }
                        }
                    }
                }
            }

            bool[,] vert = new bool[lines.Length, lines[0].Length];
            for (int i = 0; i < lines.Length; i++)
            {
                for (int j = 0; j < lines[i].Length; j++)
                {
                    vert[i, j] = true;
                    for (int k = 1; k < lines[i].Length; k++)
                    {
                        if (i - k >= 0 && i + k < lines.Length)
                        {
                            if (lines[i - k][j] != lines[i + k][j] && lines[i - k][j] != '*' && lines[i + k][j] != '*')
                            {
                                vert[i, j] = false;
                                break;
                            }
                        }
                    }
                }
            }

            int result = Int32.MaxValue;
            for (int i = 0; i < lines.Length; i++)
            {
                for (int j = 0; j < lines[i].Length; j++)
                {
                    bool ok = true;
                    for (int k = 0; k < lines.Length; k++)
                    {
                        if (!horiz[k, j] || !vert[i, k])
                        {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                    {
                        int oldSize = (lines.Length + 1) / 2;
                        int newSize = oldSize + Math.Abs(lines.Length / 2 - i) + Math.Abs(lines.Length / 2 - j);
                        result = Math.Min(result, newSize * newSize - oldSize * oldSize);
                    }
                }
            }
            return result;
        }

        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
            {
                using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
                {
                    int total = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < total; i++)
                    {
                        int k = Int32.Parse(reader.ReadLine());
                        string[] lines = new string[2 * k - 1];
                        for (int j = 0; j < lines.Length; j++)
                        {
                            lines[j] = reader.ReadLine();
                            lines[j] += new String(' ', 2 * k - 1 - lines[j].Length);
                        }
                        int ans = Solve(lines);
                        writer.WriteLine("Case #" + (i + 1) + ": " + ans);
                    }
                }
            }
        }
    }
}