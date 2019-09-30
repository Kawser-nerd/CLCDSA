using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TUP = System.Tuple<int, int, int>;
using T2 = System.Tuple<int, int>;


namespace P1
{
    class Program
    {
        static string root = @"C:\projects\GCJN\P1\P1\";
        static StreamWriter output = new StreamWriter(root + "out.txt");
        static int curCaseIndex = 1;
        public static void Log(string format, params string[] list)
        {
            output.Write(format, list);
            Console.Write(format, list);
        }

        public static void LogLine(string format, params string[] list)
        {
            output.WriteLine(format, list);
            Console.WriteLine(format, list);
        }

        public static void LogCase(string format, params string[] list)
        {
            output.WriteLine(String.Format("Case #{0}: ", curCaseIndex) + format, list);
            Console.WriteLine(String.Format("Case #{0}: ", curCaseIndex) + format, list);
            curCaseIndex++;
        }

        public static void Log(string format)
        {
            output.Write(format);
            Console.Write(format);
        }

        public static void LogLine(string format)
        {
            output.WriteLine(format);
            Console.WriteLine(format);
        }

        public static void LogCase(string format)
        {
            output.WriteLine(String.Format("Case #{0}: ", curCaseIndex) + format);
            Console.WriteLine(String.Format("Case #{0}: ", curCaseIndex) + format);
            curCaseIndex++;
        }



        static void Main(string[] args)
        {
            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            long numCases = long.Parse(input[0]);

            //long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            //IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            //scanner.MoveNext();
            //long numCases = scanner.Current;


            var lineIndex = 1;
            for (long nc = 0; nc < numCases; ++nc)
            {
                long[] data = input[lineIndex++].Split(new char[] { ' ' }).Select(y => Int64.Parse(y)).ToArray();
                var r = data[0];
                var c = data[1];

                var grid = new char[r, c];

                for (int i = 0; i < r; ++i)
                {
                    var l = input[lineIndex++];
                    for (int j = 0; j < c; ++j)
                    {
                        grid[i, j] = l[j];
                    }
                }

                for (int i = 0; i < r; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        if (grid[i, j] == '?')
                        {
                            char cf = 'a';
                            bool found = false;
                            for (int k = j + 1; k < c; ++k)
                            {
                                if (grid[i, k] != '?')
                                {
                                    cf = grid[i, k];
                                    found = true;
                                    break;
                                }
                            }

                            if (found)
                            {
                                grid[i, j] = cf;
                            }
                            else
                            {
                                for (int k = j - 1; k >= 0; k--)
                                {
                                    if (grid[i, k] != '?')
                                    {
                                        cf = grid[i, k];
                                        found = true;
                                        break;
                                    }
                                }
                                if (found)
                                {
                                    grid[i, j] = cf;
                                }
                            }
                        }
                    }
                }

                for (int i = 0; i < r; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        if (grid[i, j] == '?')
                        {
                            char cf = 'a';
                            bool found = false;
                            for (int k = i + 1; k < r; ++k)
                            {
                                if (grid[k, j] != '?')
                                {
                                    cf = grid[k, j];
                                    found = true;
                                    break;
                                }
                            }

                            if (found)
                            {
                                grid[i, j] = cf;
                            }
                            else
                            {
                                for (int k = i - 1; k >= 0; k--)
                                {
                                    if (grid[k, j] != '?')
                                    {
                                        cf = grid[k, j];
                                        found = true;
                                        break;
                                    }
                                }
                                if (found)
                                {
                                    grid[i, j] = cf;
                                }
                            }
                        }
                    }
                }

                LogCase("");
                for (int i = 0; i < r; ++i)
                {
                    for (int j = 0; j < c; ++j)
                    {
                        Log(grid[i, j].ToString());
                    }
                    Log("\n");
                }
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }

        private static bool dfs(List<List<long>> g, bool[] vis, long i)
        {
            foreach (var v in g[(int)i])
            {
                if (vis[v])
                {
                    return true;
                }
                vis[v] = true;
                if (dfs(g, vis, v))
                {
                    return true;
                }
            }
            return false;
        }
    }
}
