using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class ProblemA
    {
        static string problem = "A";

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
            long nr = nextLineAsLong();
            bool[] seen = new bool[10];
            long x = nr;
            bool done = false;
            while(!done)
            {
                seen = markSeen(x, seen);
                if (x == 0 || long.MaxValue - nr < x || seenAll(seen))
                {
                    done = true;
                    break;
                }
                x += nr;
            }
            if(seenAll(seen))
            {
                Write(string.Format("Case #{0}: {1}", caseNo, x));
            }
            else
            {
                Write(string.Format("Case #{0}: {1}", caseNo, "INSOMNIA"));
            }
        }

        static bool seenAll(bool[] seen)
        {
            foreach(bool digit in seen)
            {
                if (!digit) return false;
            }
            return true;
        }

        static bool[] markSeen(long nr, bool[] seen)
        {
            while(nr > 0)
            {
                seen[nr % 10] = true;
                nr = nr / 10;
            }
            return seen;
        }
    }
}
