using System;
using System.Collections.Generic;

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

    class SegTree
    {
        private readonly long[] Array;
        private readonly int N;

        public SegTree(int size)
        {
            N = 1;
            while (N < size)
            {
                N *= 2;
            }
            Array = new long[N * 2];
        }

        public void Update(long item, int index)
        {
            index += N;
            Array[index] = item;
            while (index > 1)
            {
                index /= 2;
                Array[index] = Array[index * 2] + Array[index * 2 + 1];
            }
        }

        private long Q(int left, int right, int k, int l, int r)
        {
            if (left <= l && r <= right)
            {
                return Array[k];
            }
            if (r <= left || right <= l)
            {
                return 0;
            }
            return Q(left, right, k * 2, l, (l + r) / 2) + Q(left, right, k * 2 + 1, (l + r) / 2, r);
        }

        public long Query(int left, int right)
        {
            return Q(left, right, 1, 0, N);
        }

        public long this[int i]
        {
            get { return Array[i + N]; }
            set { Update(value, i); }
        }
    }

    class Program
    {
        private string S;
        private const int Mod = (int)1e9 + 7;
        private int[] ACnt, CCnt, QCnt;
        private long[] PoW3;
        private List<int> BIndex;
        private void Scan()
        {
            Scanner sc = new Scanner();
            S = sc.Next();
        }

        public void Solve()
        {
            Scan();
            PoW3 = new long[100001];
            PoW3[0] = 1;
            for (int i = 1; i < 100001; i++)
            {
                PoW3[i] = (PoW3[i - 1] * 3) % Mod;
            }
            int n = S.Length;
            ACnt = new int[n + 1];
            CCnt = new int[n + 1];
            QCnt = new int[n + 1];
            BIndex = new List<int>();
            for (int i = 0; i < n; i++)
            {
                switch (S[i])
                {
                    case 'A':
                        ACnt[i + 1] = 1;
                        break;
                    case 'B':
                        BIndex.Add(i);
                        break;
                    case 'C':
                        CCnt[i + 1] = 1;
                        break;
                    case '?':
                        QCnt[i + 1] = 1;
                        BIndex.Add(i);
                        break;
                }

                ACnt[i + 1] += ACnt[i];
                CCnt[i + 1] += CCnt[i];
                QCnt[i + 1] += QCnt[i];
            }

            long ans = 0;
            foreach (int i in BIndex)
            {
                long aa = ((long)(ACnt[i] - ACnt[0]) * Pow(QCnt[i] - QCnt[0])) % Mod;
                long aq = ((long)(QCnt[i] - QCnt[0]) * Pow(QCnt[i] - QCnt[0] - 1)) % Mod;
                long cc = ((long)(CCnt[n] - CCnt[i + 1]) * Pow(QCnt[n] - QCnt[i + 1])) % Mod;
                long cq = ((long)(QCnt[n] - QCnt[i + 1]) * Pow(QCnt[n] - QCnt[i + 1] - 1)) % Mod;
                ans += ((aa + aq) % Mod * (cc + cq) % Mod) % Mod;
                ans %= Mod;
            }
            Console.WriteLine(ans);
        }

        private long Pow(int n)
        {
            if (n < 0) return 0;
            return PoW3[n];
        }

        static void Main() => new Program().Solve();
    }
}