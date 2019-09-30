using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class gcj2009
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    string[] strs = sr.ReadLine().Trim().Split(' ');
                    int L = int.Parse(strs[0]), D = int.Parse(strs[1]), N = int.Parse(strs[2]);
                    string[] DICT = new string[D];
                    for (int i = 0; i < D; ++i) DICT[i] = sr.ReadLine().Trim();
                    for (int i = 0; i < N; ++i)
                    {
                        int res = 0;
                        string str = sr.ReadLine();
                        int[] tt = new int[L];
                        int idx=0;
                        for (int j = 0; j < str.Length; ++j)
                        {
                            char ch = str[j];
                            string tstr = "" + ch;
                            if (ch == '(')
                            {
                                int pos = str.IndexOf(')', j + 1);
                                tstr = str.Substring(j + 1, pos - j - 1);
                                j = pos;
                            }
                            foreach (char tch in tstr) tt[idx] |= (1 << (tch - 'a'));
                            idx++;
                        }

                        foreach (string dstr in DICT)
                        {
                            bool ok = true;
                            for (int j = 0; j < L; ++j)
                            {
                                if ((tt[j] & (1 << (dstr[j] - 'a'))) == 0) { ok = false; break; }
                            }
                            if (ok) ++res;
                        }

                        sw.WriteLine("Case #" + (i + 1) + ": " + res);
                    }
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }

    }
}
