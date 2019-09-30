using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class ProblemB
    {

        static string problem = "B";

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
            char[] data = nextLine().ToCharArray();
            int changes = 0;
            for(int i = 1; i < data.Length; i++)
            {
                if (data[i] != data[i - 1]) changes++;
            }
            if (data[data.Length - 1] == '-') changes++;
            Write(string.Format("Case #{0}: {1}", caseNo, changes));
        }

        static bool[] flip(int top, bool[] stack)
        {
            bool[] newStack = new bool[stack.Length];
            for(int i = 0; i < top; i++)
            {
                newStack[i] = !stack[top - i - 1];
            }
            for(int i = top; i < stack.Length; i++)
            {
                newStack[i] = stack[i];
            }
            int len = newStack.Length;
            while (newStack[len - 1]) len--;
            return newStack.Take(len).ToArray();
        }
    }
}
