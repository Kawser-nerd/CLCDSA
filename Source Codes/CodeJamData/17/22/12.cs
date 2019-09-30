using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class B : GCJBase
    {
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            int iCases = int.Parse(sLines);

            System.Threading.Tasks.Task<string>[] tasks = new System.Threading.Tasks.Task<string>[iCases];

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string[] s = Console.ReadLine().Split();
                int N = int.Parse(s[0]);
                int R = int.Parse(s[1]);
                int O = int.Parse(s[2]);
                int Y = int.Parse(s[3]);
                int G = int.Parse(s[4]);
                int B = int.Parse(s[5]);
                int V = int.Parse(s[6]);
                tasks[iCase - 1] = System.Threading.Tasks.Task.Run<string>
                    (
                        () => DoWorkEasy(N,R,O,Y,G,B,V)
                    );
                //tasks[iCase - 1].Wait();
            }

            for (int iCase = 1; iCase <= iCases; iCase++)
            {
                string ret = tasks[iCase - 1].Result;
                Console.WriteLine("Case #{0}: {1}", iCase, ret);
                System.Diagnostics.Debug.WriteLine("Case #{0}: {1}", iCase, ret);
            }
        }

        private string DoWorkEasy(int N, int R, int O, int Y, int G, int B, int V)
        {
            if (R * 2 > N) return "IMPOSSIBLE";
            if (Y * 2 > N) return "IMPOSSIBLE";
            if (B * 2 > N) return "IMPOSSIBLE";

            ColorCount[] colorCount = new ColorCount[3];
            colorCount[0] = new ColorCount { Color = 'R', Count = R };
            colorCount[1] = new ColorCount { Color = 'Y', Count = Y };
            colorCount[2] = new ColorCount { Color = 'B', Count = B };

            ColorCountComparer colorCountComparer = new ColorCountComparer();
            Array.Sort(colorCount, colorCountComparer);

            char[] res = new char[N];
            res[0] = colorCount[0].Color;

            colorCountComparer.FirstColor = res[0];

            colorCount[0].Count--;

            for (int i = 1; i < N; i++)
            {
                Array.Sort(colorCount, colorCountComparer);
                if (colorCount[0].Color != res[i - 1])
                {
                    res[i] = colorCount[0].Color;
                    colorCount[0].Count--;
                } else
                {
                    res[i] = colorCount[1].Color;
                    colorCount[1].Count--;
                }
            }

            if (res[0]==res[N-1])
            {
                throw new Exception("nope");
            }

            return new string(res);
        }

        private class ColorCount
        {
            public char Color;
            public int Count;
        }

        private class ColorCountComparer : IComparer<ColorCount>
        {
            public char FirstColor;

            public int Compare(ColorCount x, ColorCount y)
            {
                if (x.Count!=y.Count)
                {
                    return -x.Count.CompareTo(y.Count);
                }

                if (x.Color == FirstColor) return -1;
                if (y.Color == FirstColor) return 1;

                return 0;
            }
        }

        private string DoWorkHard(int N, int R, int O, int Y, int G, int B, int V)
        {
            return "";
        }
    }
}
