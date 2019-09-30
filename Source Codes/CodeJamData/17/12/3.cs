using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TUP = System.Tuple<int, int, int>;
using T2 = System.Tuple<int, int>;
using System.Numerics;

namespace P2
{
    class Program
    {
        static string root = @"C:\projects\GCJN\P2\P2\";
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

            long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            var scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;

            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long N = scanner.Current;
                scanner.MoveNext();
                long P = scanner.Current;
                var R = new long[N];
                for (int i = 0; i < N; ++i)
                {
                    scanner.MoveNext();
                    R[i] = scanner.Current;
                }

                var Q = new long[N, P];
                for (int i = 0; i < N; ++i)
                {
                    for (int j = 0; j < P; ++j)
                    {
                        scanner.MoveNext();
                        Q[i, j] = scanner.Current; 
                    }
                }

                var V = new List<List<Tuple<long, long>>>();
                for (int i = 0; i < N; ++i)
                {
                    V.Add(new List<Tuple<long, long>>());
                    for (int j = 0; j < P; ++j)
                    {
                        long min = -1;
                        long max = -1;
                        //long lowB = Q[i, j] * 90;
                        //long upB = Q[i, j] * 110;

                        long approx = Q[i, j] * 100 / (110 * R[i]);
                        //long approx = ((lowB / R[i]) / 100);
                        for(long k = -2; k < 3; ++k)
                        {
                            var v = Math.Max(1, (approx + k));

                            long lowB = R[i] * 90 * v;
                            long upB = R[i] * 110 * v;


                            var val = Q[i, j] * 100;
                            if (val >= lowB && val <= upB)
                            {
                                min = v;
                                break;
                            }
                        }

                        approx = Q[i, j] * 100 / (90 * R[i]);
                        for (long k = 2; k > -3; --k)
                        {
                            var v = Math.Max(1, (approx + k));
                            long lowB = R[i] * 90 * v;
                            long upB = R[i] * 110 * v;

                            var val = Q[i, j] * 100;
                            if (val >= lowB && val <= upB)
                            {
                                max = v;
                                break;
                            }
                        }

                        if(min > 0)
                        {
                            V.Last().Add(Tuple.Create(min, max));
                        }

                    }
                    V.Last().Sort();
                }


                List<long> bounds = new List<long>();
                foreach(var l in V)
                {
                    foreach(var ll in l)
                    {
                        bounds.Add(ll.Item1);
                        bounds.Add(ll.Item2);
                    }
                }

                long totCount = 0;

                var finalList = bounds.Distinct().OrderBy(x => x).ToList();
                for(int i = 0; i < finalList.Count; ++i)
                {
                    var v = finalList[i];
                    bool isGood = V.All(x => x.Any(y => y.Item1 <= v && y.Item2 >= v));
                    if(isGood)
                    {
                        i--;
                        totCount++;
                        foreach(var list in V)
                        {
                            var index = list.FindIndex(x => x.Item1 <= v && x.Item2 >= v);
                            list.RemoveAt(index);
                        }
                    }
                }

                LogCase(totCount.ToString());
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
