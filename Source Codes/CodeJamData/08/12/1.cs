using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Milkshake
{
    class MilkShake
    {
        private static int n;
        private static int m;
        private static int[] flavor;
        private static int[] malted;
        private static List<int>[] unmalted;
        private static bool ok;

        private static bool test(int index)
        {
            for (int k = 0; k < unmalted[index].Count; k++)
                if (flavor[unmalted[index][k]] == 0)
                    return true;
            if (malted[index] != -1)
                if (flavor[malted[index]] == 1)
                    return true;
            return false;
        }

        private static void getFlover()
        {
            ok = true;
            for (int k = 0; k < m; k++)
                flavor[k] = 0;
            while (true)
            {
                int k = 0;
                while ((k < n) && (test(k)))
                    k++;
                if (k == n)                
                    break;
                if (malted[k] == -1)
                {
                    ok = false;
                    break;
                }
                flavor[malted[k]] = 1;
            }
        }

        public static void solve()
        {
            FileStream fin = new FileStream("b02.in", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fin);
            FileStream fout = new FileStream("b.out", FileMode.Create, FileAccess.Write);
            StreamWriter sw = new StreamWriter(fout);

            int numTestCase = Int32.Parse(sr.ReadLine());
            for (int t = 1; t <= numTestCase; t++)
            {
                m = Int32.Parse(sr.ReadLine());
                n = Int32.Parse(sr.ReadLine());
                flavor = new int[m];
                malted = new int[n];
                for (int k = 0; k < n; k++)
                    malted[k] = -1;
                unmalted = new List<int>[n];
                for (int i = 0; i < n; i++)
                    unmalted [i] = new List<int>();
                for (int k = 0; k < n; k++)
                {
                    string[] s = sr.ReadLine().Split(' ');
                    int num = Int32.Parse(s[0]);
                    int j = 2;
                    for (int i = 0; i < num; i++)
                    {
                        if (s[j].CompareTo("0") == 0)
                            unmalted [k].Add(Int32.Parse(s[j - 1]) - 1);
                        else
                            malted [k] = Int32.Parse(s[j - 1]) - 1;
                        j += 2;
                    }
                }

                getFlover();
                if (ok)
                {
                    sw.Write("Case #" + t + ":");
                    for (int i = 0; i < m; i++)
                        sw.Write(" " + flavor[i]);
                    sw.WriteLine();
                }
                else
                    sw.WriteLine("Case #" + t + ": IMPOSSIBLE");
            }

            sr.Close();
            fin.Close();
            sw.Close();
            fout.Close();
        }

    }
}
