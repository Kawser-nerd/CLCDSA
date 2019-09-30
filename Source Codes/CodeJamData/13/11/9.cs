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

            public BigInteger R;
            public BigInteger T;

            public static BigInteger[] ReadInts(string s)
            {
                string[] splitted = s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                int num = splitted.Length;
                BigInteger[] r = new BigInteger[num];
                for (int i = 0; i < num; i++)
                    r[i] = BigInteger.Parse(splitted[i]);
                return r;
            }

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num };

                BigInteger[] q = ReadInts(sr.ReadLine());

                t.R = q[0];
                t.T = q[1];
                
                return t;
            }

            public static BigInteger sqrt(BigInteger x)
            {
                if (x <= 1)
                    return x;
                BigInteger two = 2;
                BigInteger y;
                // starting with y = x / 2 avoids magnitude issues with x squared
                for (y = BigInteger.Divide(x, 2);
                        y > BigInteger.Divide(x, y);
                        y = BigInteger.Divide(BigInteger.Divide(x, y) + y, 2));
                return y;
            }

            public static BigInteger squared(BigInteger x)
            {
                return x * x;
            }

            private string SolveInner()
            {
                BigInteger MaxRings = BigInteger.Divide(sqrt(8*T + squared(2*R-1)) - 2*R + 1 , 4);
                return MaxRings.ToString();
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
