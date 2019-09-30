using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class GCJIO
    {
        private string path;
        private string problem;
        private string[] lines;
        private List<string> output = new List<string>();
        private int line_no = 0;

        public GCJIO(string path, string problem)
        {
            this.path = path;
            this.problem = problem;
            if (!System.IO.Directory.Exists(path)) System.IO.Directory.CreateDirectory(path);
            if (!System.IO.File.Exists(path + problem + ".in"))
            {
                System.IO.File.WriteAllText(path + problem + ".in", "0");
            }
            lines = System.IO.File.ReadAllLines(path + problem + ".in");
        }

        public void WriteOutput()
        {
            System.IO.File.WriteAllLines(path + problem + ".out", output);
        }

        public void Write<T>(T data)
        {
            output.Add(data.ToString());
        }

        public bool hasNextLine()
        {
            return line_no < lines.Length;
        }

        public string nextLine()
        {
            return lines[line_no++];
        }

        public int nextLineAsInt()
        {
            return int.Parse(nextLine());
        }

        public long nextLineAsLong()
        {
            return long.Parse(nextLine());
        }

        public ulong nextLineAsULong()
        {
            return ulong.Parse(nextLine());
        }

        public string[] nextLineSeparated()
        {
            return nextLine().Split(' ');
        }

        public int[] nextLineSeparatedAsInt()
        {
            return nextLineSeparated().Select(t => int.Parse(t)).ToArray();
        }

        public long[] nextLineSeparatedAsLong()
        {
            return nextLineSeparated().Select(t => long.Parse(t)).ToArray();
        }

        public ulong[] nextLineSeparatedAsULong()
        {
            return nextLineSeparated().Select(t => ulong.Parse(t)).ToArray();
        }
    }

    public interface IProblemSolver
    {
        string Solve(int caseNo);
        void Seed();
        string BruteForce(int caseNo);
        bool UsedBruteForce { get; }
        void ProcessInput();
    }

    class GCJ
    {
        public static string path = "E:\\dev\\codejam\\2015\\CodeJam\\CodeJam\\io\\";

        public static GCJIO io;

        public static void init(string contest, string problem)
        {
            io = new GCJIO(path + contest + "\\", problem);
        }

        static void Main(string[] args)
        {
            init("2017r1c", "B");
            IProblemSolver solution = new _2017r1c.ProblemB();
            int T = io.nextLineAsInt();
            solution.Seed();
            for (int i = 0; i < T; i++)
            {
#if DEBUG
                var timer = new System.Diagnostics.Stopwatch();
                timer.Start();
#endif
                Console.WriteLine(string.Format("Working on Case #{0}", (i + 1)));
                solution.ProcessInput();
                string sol;
                if (solution.UsedBruteForce)
                {
                    string bf = solution.BruteForce(i + 1);
                    sol = solution.Solve(i + 1);
                    if (bf != sol)
                    {
                        Console.WriteLine("Solution missmatch on Case #{0}: BF:{1} - SOL:{2}", i + 1, bf, sol);
                    }
                }
                else
                {
                    sol = solution.Solve(i + 1);
                }
                io.Write(string.Format("Case #{0}: {1}", i + 1, sol));
#if DEBUG
                timer.Stop();
                Console.WriteLine(string.Format("solved in {0}ms", timer.ElapsedMilliseconds));
#endif
            }
            io.WriteOutput();
            Console.WriteLine("FINISHED COMPUTATION");
            Console.ReadKey();
        }
    }
}
