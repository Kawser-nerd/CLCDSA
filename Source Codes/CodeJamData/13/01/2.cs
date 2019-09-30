using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ExampleApp
{
    class Program
    {
        class Task
        {
            public int Number;

            public string[] Board = new string[4];

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num};

                t.Board[0] = sr.ReadLine();
                t.Board[1] = sr.ReadLine();
                t.Board[2] = sr.ReadLine();
                t.Board[3] = sr.ReadLine();
                sr.ReadLine();

                return t;
            }

            private int Count(char charToCount)
            {
                return Board.Select(a => a.Count(c => c == charToCount)).Sum();
            }

            private bool Won(char p)
            {
                Func<char, bool> isOk = c => (c == p || c == 'T');
                for (int i = 0; i < 4; i++)
                {
                    if (Board[i].All(isOk))
                        return true;
                    if (isOk(Board[0][i]) && isOk(Board[1][i]) && isOk(Board[2][i]) && isOk(Board[3][i]))
                        return true;
                }
                if (isOk(Board[0][0]) && isOk(Board[1][1]) && isOk(Board[2][2]) && isOk(Board[3][3]))
                    return true;
                if (isOk(Board[0][3]) && isOk(Board[1][2]) && isOk(Board[2][1]) && isOk(Board[3][0]))
                    return true;
                return false;
            }

            private string SolveInner()
            {
                if (Won('X'))
                    return "X won";
                if (Won('O'))
                    return "O won";

                int spaceNum = Count('.');

                if (spaceNum == 0)
                    return "Draw";

                return "Game has not completed";
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
