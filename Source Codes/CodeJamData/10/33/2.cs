using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GCJ2010
{
    class Round1C
    {
        public void SloveFile(string inputfile)
        {
            using (StreamReader reader = new StreamReader(inputfile))
            using (StreamWriter writer = new StreamWriter(inputfile + ".out"))
            {
                int n = int.Parse(reader.ReadLine());
                for (int i = 1; i <= n; i++)
                {
                    var ss = reader.ReadLine().Split();

                    int M = int.Parse(ss[0]);
                    int N = int.Parse(ss[1]);

                    int[,] map = new int[M, N];

                    for (int j = 0; j < M; j++)
                    {
                        var line = reader.ReadLine();
                        for (int k = 0; k < N / 4; k++)
                        {
                            var s = GetBits(line[k]);
                            map[j, k * 4] = s[0] == '1' ? 1 : -1;
                            map[j, k * 4 + 1] = s[1] == '1' ? 1 : -1;
                            map[j, k * 4 + 2] = s[2] == '1' ? 1 : -1;
                            map[j, k * 4 + 3] = s[3] == '1' ? 1 : -1;
                        }
                    }

                   // PrintMap(M, N, map, "Map Read");

                    Dictionary<int, int> retDic;
                    int r = SloveCase(M, N, map, out retDic);
                    writer.WriteLine("Case #{0}: {1}", i, r);
                    Console.WriteLine("Case #{0}: {1}", i, r);
                    for (int j = N; j >= 0; j--)
                    {
                        if (retDic.ContainsKey(j))
                        {
                            writer.WriteLine("{0} {1}", j, retDic[j]);
                            Console.WriteLine("{0} {1}", j, retDic[j]);
                        }
                    }
                }
            }
        }

        public int SloveCase(int M, int N, int[,] map, out Dictionary<int, int> retDic)
        {
            int n = Math.Min(M, N);

            retDic = new Dictionary<int, int>();

            for (int k = n; k >= 1; k--)
            {
                for (int y = 0; y <= M - k; y++)
                {
                    for (int x = 0; x <= N - k; x++)
                    {
                        if (TryMarkSquare(map, x, y, k))
                        {
                           // PrintMap(M, N, map, "GetSquare");
                            int v;
                            if (retDic.TryGetValue(k, out v))
                            {
                                retDic[k] = v + 1;
                            }
                            else
                            {
                                retDic.Add(k, 1);
                            }
                        }
                    }
                }
            }
            return retDic.Keys.Count;
        }

        public bool TryMarkSquare(int[,] map, int x, int y, int k)
        {
            int tag = 0;

            for (int dy = 0; dy < k; dy++)
            {
                for (int dx = 0; dx < k; dx++)
                {
                    int a = map[y + dy, x + dx];
                    if (a == 0) // Cutted
                        return false;

                    if (tag == 0)
                    {
                        tag = a;
                    } else {
                        tag = tag * -1;
                    }

                    if (tag != a)
                        return false;
                }

                if (k % 2 == 0)
                    tag = tag * -1;
            }

            for (int dy = 0; dy < k; dy++)
            {
                for (int dx = 0; dx < k; dx++)
                {
                    map[y + dy, x + dx] = 0;
                }
            }
            return true;
        }

        public void PrintMap(int M, int N, int[,] map, string message)
        {
            Console.WriteLine("Map {0}", message);
            for (int y = 0; y < M; y++)
            {
                for (int x = 0; x < N; x++)
                {
                    switch (map[y, x])
                    {
                        case 1:
                            Console.Write("+");
                            break;
                        case -1:
                            Console.Write("0");
                            break;
                        case 0:
                            Console.Write(" ");
                            break;
                    }
                }
                Console.WriteLine();
            }
        }

        public string GetBits(char a)
        {
            switch (a)
            {
                case '0':
                    return "0000";
                case '1':
                    return "0001";
                case '2':
                    return "0010";
                case '3':
                    return "0011";
                case '4':
                    return "0100";
                case '5':
                    return "0101";
                case '6':
                    return "0110";
                case '7':
                    return "0111";
                case '8':
                    return "1000";
                case '9':
                    return "1001";
                case 'A':
                    return "1010";
                case 'B':
                    return "1011";
                case 'C':
                    return "1100";
                case 'D':
                    return "1101";
                case 'E':
                    return "1110";
                case 'F':
                    return "1111";
            }
            throw new FormatException("Unexcepted Char: " + a);
        }
    }
}
