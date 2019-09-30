using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;
using System.Threading;
using System.IO;

namespace D
{
    class MyBitArray
    {
        public bool[] b = new bool[36];

        public override bool Equals(object obj)
        {
            if (obj == null || !(obj is MyBitArray))
                return false;

            MyBitArray mba = obj as MyBitArray;
            for (int i = 0; i < 36; i++)
                if (mba.b[i] != b[i])
                    return false;
            return true;
        }

        public override int GetHashCode()
        {
            int res = 0;
            for (int i = 0; i < 32; i++)
            {
                if (b[i])
                    res |= (1 << i);
            }
            return res;
        }

        public MyBitArray Clone()
        {
            MyBitArray res = new MyBitArray();
            for (int i = 0; i < 36; i++)
                res.b[i] = b[i];
            return res;
        }
    }

    class Program
    {
        static void Solve(int casenum)
        {
            Console.Write("Case #{0}: ", casenum);
            string[] line = Console.ReadLine().Split();
            int P = int.Parse(line[0]);
            int W = int.Parse(line[1]);

            bool[,] w = new bool[P, P];
            line = Console.ReadLine().Split();

            for (int i = 0; i < W; i++)
            {
                string[] x = line[i].Split(',');
                int a = int.Parse(x[0]);
                int b = int.Parse(x[1]);
                w[a, b] = w[b, a] = true;
            }

            if (w[0, 1])
            {
                int count = 0;
                for (int i = 1; i < P; i++)
                    if (w[0, i])
                        count++;

                Console.WriteLine("0 {0}", count);
                return;
            }

            //HashSet<MyBitArray> gg = new HashSet<MyBitArray>();
            //MyBitArray gga = new MyBitArray();
            //MyBitArray ggb = new MyBitArray();
            //gga.b[33] = true;
            //ggb.b[33] = true;
            //gg.Add(gga);
            //gg.Add(ggb);


            //Console.WriteLine();

            bool thr = false;
            HashSet<MyBitArray> curr = new HashSet<MyBitArray>();
            HashSet<MyBitArray> next = new HashSet<MyBitArray>();

            MyBitArray init = new MyBitArray();
            init.b[0] = true;
            curr.Add(init);

            while (!thr)
            {
                next.Clear();
                foreach (MyBitArray mba in curr)
                {
                    for (int i = 0; i < P; i++)
                    {
                        if (!mba.b[i])
                            continue;

                        for (int j = 0; j < P; j++)
                        {
                            if (mba.b[j])
                                continue;
                            if (!w[i, j])
                                continue;

                            MyBitArray m2 = mba.Clone();
                            m2.b[j] = true;

                            next.Add(m2);

                            if (w[j, 1])
                                thr = true;
                        }
                    }
                }

                HashSet<MyBitArray> tmp = curr;
                curr = next;
                next = tmp;
            }

            int maxat = -1;
            foreach (MyBitArray mba in curr)
            {
                bool isa = false;
                for (int i = 0; i < P && !isa; i++)
                    if (mba.b[i] && w[i, 1])
                        isa = true;

                if (!isa)
                    continue;

                int count = 0;
                for (int i = 0; i < P; i++)
                {
                    if (mba.b[i])
                        continue;

                    isa = false;
                    for (int j = 0; j < P && !isa; j++)
                        if (mba.b[j] && w[j, i])
                            isa = true;

                    if (isa)
                        count++;
                }

                maxat = Math.Max(maxat, count);
            }

            MyBitArray mbx = curr.First();
            int cnt2 = 0;
            for (int i = 1; i < P; i++)
                if (mbx.b[i])
                    cnt2++;

            Console.WriteLine("{0} {1}", cnt2, maxat);

        }

        static void Main(string[] args)
        {
            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
#if DEBUG
            Console.SetIn(new StreamReader("input.txt"));
#endif

            int T = int.Parse(Console.ReadLine());
            for (int t = 0; t < T; t++)
            {
                Solve(t + 1);
#if !DEBUG
                Console.Error.WriteLine("Solved: {0}", t + 1);
#endif
            }
        }
    }
}
