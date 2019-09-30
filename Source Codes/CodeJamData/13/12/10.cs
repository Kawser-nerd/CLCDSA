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

            public int E;
            public int R;
            public int[] V;
            
            public static int[] ReadInts(string s)
            {
                string[] splitted = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int num = splitted.Length;
                int[] r = new int[num];
                for (int i = 0; i < num; i++)
                    r[i] = int.Parse(splitted[i]);
                return r;
            }

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num };

                int[] q = ReadInts(sr.ReadLine());

                t.E = q[0];
                t.R = q[1];

                t.V = ReadInts(sr.ReadLine());

                return t;
            }



            private string SolveInner()
            {
                long gain = 0;

                long C = E - R;
                long toRecover = (E+R-1)/R;
                for (long i = 0; i < V.Length; i++)
                {
                    C += R;
                    if (V[i] <= 0)
                        continue;

                    long ToSpend = C;
                    for (long j = i + 1; j < V.Length; j++)
                    {
                        // try to save some for jth activity
                        long passed = j - i;
                        if (toRecover <= passed)
                            break;

                        if (V[j] <= V[i])
                            continue;
                        long maxEnergy = C + passed * R;
                        long spend = Math.Max(maxEnergy - E, 0);
                        ToSpend = Math.Min(ToSpend, spend);
                        if (ToSpend == 0)
                            break;
                    }
                    C -= ToSpend;
                    gain += V[i] * ToSpend;
                }
                
                return gain.ToString();
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
