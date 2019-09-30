using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            return Array().Select(int.Parse).ToArray();
        }
        public long[] LongArray()
        {
            return Array().Select(long.Parse).ToArray();
        }
    }

    class Program
    {
        private int N;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
        }

        public void Solve()
        {
            long sum = 0;
            var ans = new List<int>();
            Scan();
            switch (N)
            {
                case 3:
                    Console.WriteLine("2 5 63");
                    return;
                case 4:
                    Console.Write("2 3 4 9");
                    return;
                case 5:
                    Console.WriteLine("2 3 4 6 9");
                    return;
            }
            var p = new int[] { 2, 3, 4, 6 };
            for (int i = 0; ans.Count < N; i++)
            {
                foreach (var j in p)
                {
                    sum += 6 * i + j;
                    ans.Add(6 * i + j);
                    if (ans.Count >= N)
                    {
                        break;
                    }
                }
            }

            switch (sum % 6)
            {
                case 2:
                    ans.Remove(8);
                    for (int i = ans[ans.Count - 1] + 1; ; i++)
                    {
                        if (i % 6 == 0)
                        {
                            ans.Add(i);
                            break;
                        }
                    }
                    break;
                case 3:
                    ans.Remove(9);
                    for (int i = ans[ans.Count - 1] + 1; ; i++)
                    {
                        if (i % 6 == 0)
                        {
                            ans.Add(i);
                            break;
                        }
                    }
                    break;
                case 5:
                    ans.Remove(9);
                    for (int i = ans[ans.Count - 1] + 1; ; i++)
                    {
                        if (i % 6 == 4)
                        {
                            ans.Add(i);
                            break;
                        }
                    }
                    break;
            }
            ans.Sort();
            Console.WriteLine(string.Join(" ", ans));
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}