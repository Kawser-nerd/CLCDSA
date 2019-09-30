using System.IO;
using System.Linq;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamReader sr = new StreamReader(@"..\..\a.in"))
            using (StreamWriter sw = new StreamWriter(@"..\..\a.out"))
            {
                int testcount = int.Parse(sr.ReadLine());

                for (int t = 1; t <= testcount; t++)
                {
                    string[] input = sr.ReadLine().Split(' ');
                    int R = int.Parse(input[0]);
                    int C = int.Parse(input[1]);

                    char[][] data = Enumerable.Range(0, R).Select(i => sr.ReadLine().ToCharArray()).ToArray();

                    for (int r = 0; r < R; ++r)
                    {
                        bool empty = true;
                        for (int c = 0; c < C; ++c)
                        {
                            if (data[r][c] != '?')
                            {
                                for (int i = c - 1; i >= 0; --i) if (data[r][i] == '?') data[r][i] = data[r][c]; else break;
                                for (int i = c + 1; i < C; ++i) if (data[r][i] == '?') data[r][i] = data[r][c]; else break;
                                empty = false;
                            }
                        }
                        if (empty) data[r] = null;
                    }
                    for (int r = 0; r < R; ++r)
                    {
                        if (data[r] != null)
                        {
                            for (int i = r - 1; i >= 0; --i) if (data[i] == null) data[i] = data[r]; else break;
                            for (int i = r + 1; i < R; ++i) if (data[i] == null) data[i] = data[r]; else break;
                        }
                    }

                    sw.WriteLine($"Case #{t}:");
                    sw.WriteLine(string.Join("\n", data.Select(row => new string(row))));
                }
            }
        }
    }
}