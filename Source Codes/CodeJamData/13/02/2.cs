using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

using System.Numerics;

namespace ExampleApp
{
    class Program
    {
        class Task
        {
            public int Number;

            public int[][] Lawn;

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num};

                string line = sr.ReadLine();

                string[] splitted = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                int n = int.Parse(splitted[0]);
                t.Lawn = new int[n][];
                int m = int.Parse(splitted[1]);
                for (int i = 0; i < n; i++)
                {
                    t.Lawn[i] = new int[m];
                    splitted = sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    for (int j = 0; j < m; j++)
                        t.Lawn[i][j] = int.Parse(splitted[j]);
                }
                return t;
            }

            private string SolveInner()
            {
                int[] maxHeightI = new int[Lawn.Length];
                for (int i = 0; i < Lawn.Length; i++)
                {
                    maxHeightI[i] = Lawn[i].Max();
                }
                int[] maxHeightJ = new int[Lawn[0].Length];
                for (int j = 0; j < Lawn[0].Length; j++)
                {
                    maxHeightJ[j] = Enumerable.Range(0, Lawn.Length).Select(row => Lawn[row][j]).Max();
                }

                for (int i = 0; i < Lawn.Length; i++)
                    for (int j = 0; j < Lawn[0].Length; j++)
                        if (Lawn[i][j] != maxHeightI[i] && Lawn[i][j] != maxHeightJ[j])
                            return "NO";
                return "YES";
            }

            public string[] Solve()
            {
                return new string[] { String.Format("Case #{0}: {1}", Number, SolveInner()) };
            }
        }

        static void Main(string[] args)
        {
            using (StreamWriter sw = new StreamWriter(new FileStream(args[1], FileMode.Create)))
            {
                int tasksCount;

                List<Task> tasks = new List<Task>();
                using (StreamReader sr = new StreamReader(new FileStream(args[0], FileMode.Open)))
                {
                    tasksCount = int.Parse(sr.ReadLine());
                    for (int i = 0; i < tasksCount; i++)
                        tasks.Add(Task.ReadMe(i + 1, sr));
                }

                foreach (Task t in tasks)
                {
                    string[] solution = t.Solve();
                    WriteLinesToOutput(sw, solution);
                }
            }
        }

        private static void WriteLinesToOutput(StreamWriter sw, params string[] lines)
        {
            foreach (string line in lines)
                sw.WriteLine(line);
        }
    }
}
