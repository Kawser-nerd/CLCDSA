using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class ProblemD
    {
        static string problem = "D";

        static string[] lines = System.IO.File.ReadAllLines("E:\\dev\\codejam\\2015\\CodeJam\\CodeJam\\io\\" + problem + ".in");
        static List<string> output = new List<string>();
        static int line_no = 0;

        static void WriteOutput()
        {
            System.IO.File.WriteAllLines("E:\\dev\\codejam\\2015\\CodeJam\\CodeJam\\io\\" + problem + ".out", output);
        }

        static void Write<T>(T data)
        {
            output.Add(data.ToString());
        }

        static bool hasNextLine()
        {
            return line_no < lines.Length;
        }

        static string nextLine()
        {
            return lines[line_no++];
        }

        static int nextLineAsInt()
        {
            return int.Parse(nextLine());
        }

        static long nextLineAsLong()
        {
            return long.Parse(nextLine());
        }

        static string[] nextLineSeparated()
        {
            return nextLine().Split(' ');
        }

        static int[] nextLineSeparatedAsInt()
        {
            return nextLineSeparated().Select(t => int.Parse(t)).ToArray();
        }

        static long[] nextLineSeparatedAsLong()
        {
            return nextLineSeparated().Select(t => long.Parse(t)).ToArray();
        }

        static void Main(string[] args)
        {
            int T = nextLineAsInt();
            for (int i = 0; i < T; i++)
            {
                solve(i + 1);
            }
            WriteOutput();
        }

        static void solve(int caseNo)
        {
            int[] data = nextLineSeparatedAsInt();
            int k = data[0];
            int c = data[1];
            int s = data[2];
            int req = (int)Math.Ceiling(1.0 * k / c);
            if(req > s)
            {
                Write(string.Format("Case #{0}: {1}", caseNo, "IMPOSSIBLE"));
            }
            else
            {
                List<string> results = new List<string>();
                int cnt = 0;
                for(var i = 0; i < req; i++)
                {
                    List<int> group = new List<int>();
                    for(var j = 0; j < c; j++)
                    {
                        group.Add(cnt++);
                        if (cnt >= k) cnt--;
                    }
                    results.Add(getValue(group.ToArray(), k).ToString());
                }
                Write(string.Format("Case #{0}: {1}", caseNo, string.Join(" ", results)));
            }
        }

        static BigInteger getValue(int[] group, int k)
        {
            BigInteger val = BigInteger.One;
            for(var i = 0; i < group.Length; i++)
            {
                BigInteger pow = BigInteger.Pow(new BigInteger(k), group.Length - i - 1);
                val = BigInteger.Add(val, BigInteger.Multiply(pow, new BigInteger(group[i])));
            }
            return val;
        }
    }
}
