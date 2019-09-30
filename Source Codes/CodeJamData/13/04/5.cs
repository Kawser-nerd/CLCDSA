using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class D
    {
        private static ThreadStart s_threadStart = new D().Go;
        private static bool s_time = false;

        int K;
        int N;
        Chest[] chests;
        HashSet<int>[] keyMap;
        HashSet<int> keys;
        int[] keyExist;
        int[] keyNeed;
        int tot;
        bool[] visited;

        class Chest
        {
            public int KeyOpen;
            public Dictionary<int, int> KeyHas = new Dictionary<int, int>();

            public void SetKeyOpen(int k)
            {
                KeyOpen = k;
            }

            public void AddKey(int k, int val = 1)
            {
                if (!KeyHas.ContainsKey(k)) KeyHas[k] = 0;
                KeyHas[k] += val;
            }

            public int GetKeyOfType(int k)
            {
                if(KeyHas.ContainsKey(k)) return KeyHas[k];
                return 0;
            }
        }

        private void Test(int tt)
        {
            K = GetInt();
            N = GetInt();
            chests = new Chest[N + 1];
            keyMap = new HashSet<int>[201];
            for (int i = 1; i < 201; i++)
            {
                keyMap[i] = new HashSet<int>();
            }
            for (int i = 0; i <= N; i++)
            {
                chests[i] = new Chest();
            }

            keyExist = new int[201];
            keyNeed = new int[201];

            for (int i = 0; i < K; i++)
            {
                int x = GetInt();
                keyExist[x]++;
                chests[0].AddKey(x);
            }
            for (int i = 1; i <= N; i++)
            {
                int x = GetInt();
                keyNeed[x]++;
                keyMap[x].Add(i);
                chests[i].SetKeyOpen(x);

                x = GetInt();
                for (int j = 0; j < x; j++)
                {
                    int y = GetInt();
                    keyExist[y]++;
                    chests[i].AddKey(y);
                }
            }

            keys = new HashSet<int>();
            for (int i = 1; i < 201; i++) if (keyMap[i].Count > 0) keys.Add(i);

            //check impossible
            foreach (var key in keys)
            {
                if (keyExist[key] < keyNeed[key])
                {
                    Wl(tt, "IMPOSSIBLE");
                    return;
                }
            }
            if (!BFS(N))
            {
                Wl(tt, "IMPOSSIBLE");
                return;
            }

            tot = 0;
            int[] res = new int[N];
            while (tot < N)
            {
                int a = 1;
                for (; a <= N; a++)
                {
                    if (chests[a] != null && Check(a))
                    {
                        Chest ch = chests[a];
                        res[tot++] = a;
                        chests[a] = null;

                        chests[0].KeyHas[ch.KeyOpen]--;
                        foreach(var pair in ch.KeyHas)
                        {
                            chests[0].AddKey(pair.Key, pair.Value);
                        }

                        break;
                    }
                }
            }

            Wl(tt, string.Join(" ", res));
        }

        bool Check(int a)
        {
            Chest ch = chests[a];
            Chest start = chests[0];

            if (start.GetKeyOfType(ch.KeyOpen) < 1)
                return false;

            //connectivity
            Chest newStart = new Chest();
            newStart.KeyHas = new Dictionary<int, int>(start.KeyHas);
            newStart.KeyHas[ch.KeyOpen]--;
            foreach (var pair in ch.KeyHas)
                newStart.AddKey(pair.Key, pair.Value);

            chests[0] = newStart;
            chests[a] = null;
            bool res = BFS(N - tot - 1);
            chests[a] = ch;
            chests[0] = start;
            return res;
        }

        bool BFS(int tot)
        {
            if(tot==0) return true;
            Queue<int> q = new Queue<int>();
            q.Enqueue(0);
            visited = new bool[N + 1];
            int count = 0;
            while (q.Count > 0)
            {
                int x = q.Dequeue();
                foreach (var pair in chests[x].KeyHas.Where(pair => pair.Value > 0))
                {
                    foreach (int chNo in keyMap[pair.Key])
                    {
                        if (chests[chNo] != null && !visited[chNo])
                        {
                            count++;
                            visited[chNo] = true;
                            q.Enqueue(chNo);
                            if (count == tot) return true;
                        }
                    }
                }
            }
            return false;
        }

        #region Template

        private void Go()
        {
            int T = GetInt();
            for (int t = 1; t <= T; t++)
            {
                Test(t);
            }
        }

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            Thread main = new Thread(new ThreadStart(s_threadStart), 512 * 1024 * 1024);
            timer.Start();
            main.Start();
            main.Join();
            timer.Stop();
            if (s_time)
                Console.WriteLine(timer.ElapsedMilliseconds);
        }

        private static IEnumerator<string> ioEnum;
        private static string GetString()
        {
            do
            {
                while (ioEnum == null || !ioEnum.MoveNext())
                {
                    ioEnum = Console.ReadLine().Split().AsEnumerable().GetEnumerator();
                }
            } while (string.IsNullOrEmpty(ioEnum.Current));

            return ioEnum.Current;
        }

        private static int GetInt()
        {
            return int.Parse(GetString());
        }

        private static long GetLong()
        {
            return long.Parse(GetString());
        }

        private static double GetDouble()
        {
            return double.Parse(GetString());
        }

        private static List<int> GetIntArr(int n)
        {
            List<int> ret = new List<int>(n);
            for (int i = 0; i < n; i++)
            {
                ret.Add(GetInt());
            }
            return ret;
        }

        private static void Wl<T>(int testCase, T o)
        {
            Console.WriteLine("Case #{0}: {1}", testCase, o.ToString());
        }

        private static void Wl<T>(int testCase, IEnumerable<T> enumerable)
        {
            Wl(testCase, string.Join(" ", enumerable.Select(e => e.ToString()).ToArray()));
        }

        #endregion
    }
}