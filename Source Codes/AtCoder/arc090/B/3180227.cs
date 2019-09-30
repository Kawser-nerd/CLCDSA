using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

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
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    struct S
    {
        public int R, D;
    }

    class Program
    {
        private int N, M;
        private List<S>[] List;
        private Dictionary<long, int> PoSToN;
        private Dictionary<int, long> NToPos;
        private HashSet<int> Hs;

        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            M = sc.NextInt();
            List = new List<S>[N];
            for (int i = 0; i < N; i++)
            {
                List[i] = new List<S>();
            }
            for (int i = 0; i < M; i++)
            {
                int l = sc.NextInt() - 1;
                int r = sc.NextInt() - 1;
                int d = sc.NextInt();
                List[l].Add(new S { R = r, D = d });
                List[r].Add(new S { D = -d, R = l });
            }
        }

        private bool Search(int n)
        {
            long pos = NToPos[n];
            foreach (var s in List[n])
            {
                //Console.WriteLine($"{n} {s.R}");
                long next = pos + s.D;
                int o;

                long p;
                if (NToPos.TryGetValue(s.R, out p))
                {
                    //Console.WriteLine($"{s.R} {p}");
                    if (p != next)
                        return false;
                }
                if (Hs.Add(s.R))
                {
                    NToPos[s.R] = next;
                    PoSToN[next] = s.R;
                    if (!Search(s.R)) return false;
                }
            }

            return true;
        }

        public void Solve()
        {
            Scan();
            Hs = new HashSet<int>();
            for (int i = 0; i < N; i++)
            {
                if (Hs.Contains(i)) continue;
                NToPos = new Dictionary<int, long>();
                PoSToN = new Dictionary<long, int>();
                NToPos[i] = 0;
                PoSToN[0] = i;
                Hs.Add(i);
                if (!Search(i))
                {

                    Console.WriteLine("No");
                    return;
                }
            }
            Console.WriteLine("Yes");

        }

        static void Main() => new Program().Solve();
    }
}