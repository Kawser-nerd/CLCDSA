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

            public BigInteger A, B;

            public static Task ReadMe(int num, StreamReader sr)
            {
                Task t = new Task() { Number = num};

                string line = sr.ReadLine();

                string[] splitted = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                t.A = BigInteger.Parse(splitted[0]);
                t.B = BigInteger.Parse(splitted[1]);

                return t;
            }

            public static bool IsPalindrome(BigInteger a)
            {
                string l = a.ToString();
                return l.Reverse().SequenceEqual(l);
            }

            public static IEnumerable<BigInteger> GenerateAllPalindromes(int len)
            {
                int halfLen = (len + 1) / 2;
                bool even = (len % 2 == 0);
                int maxHalf = 1;
                for (int i = 0; i < halfLen; i++)
                    maxHalf *= 10;
                string form = "D" + halfLen;
                for (int i = 1; i < maxHalf; i++)
                {
                    if (i % 10 == 0)
                        continue;
                    string toLine = i.ToString(form) ;
                    string palindrome;
                    if (even)
                    {
                        palindrome = new string(toLine.Reverse().ToArray()) + toLine;
                    }
                    else
                    {
                        palindrome = new string(toLine.Where((c, ind) => ind != 0).Reverse().ToArray()) + toLine;
                    }
                    yield return BigInteger.Parse(palindrome);
                }
            }

            public static IEnumerable<BigInteger> GeneratePalindromesUpToLen(int len)
            {
                for (int i = 1; i <= len; i++)
                    foreach (var j in GenerateAllPalindromes(i))
                        yield return j;
            }

            private static BigInteger[] integ = GeneratePalindromesUpToLen(10).Where(a => IsPalindrome(a * a)).ToArray();

            private string SolveInner()
            {
                BigInteger r = 0;
                foreach (var i in integ)
                {
                    var j = i * i;
                    if (this.A <= j && j <= this.B)
                        r++;
                }
                return r.ToString();
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
