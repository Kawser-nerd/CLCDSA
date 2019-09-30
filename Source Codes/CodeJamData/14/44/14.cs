using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace test {
    public class Ctest {
        public void main(String FileName) {
            FileStream fs, fs2;
            StreamReader sr = null;
            StreamWriter sw = null;

            try {
                fs = new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                sr = new StreamReader(fs, Encoding.Default);
                fs2 = new FileStream("output.txt", FileMode.Create, FileAccess.ReadWrite, FileShare.Read);
                sw = new StreamWriter(fs2, Encoding.Default);

                //header
                string str = sr.ReadLine();

                int iSize = int.Parse(str);

                for (int ip = 0; ip < iSize; ip++) {
                    string[] strs;
                    str = sr.ReadLine();
                    strs = str.Split(new char[] { ' ' });
                    int M = int.Parse(strs[0]);
                    int N = int.Parse(strs[1]);

                    List<string> lstdata = new List<string>();
                    for (int i = 0; i < M; i++) {
                        str = sr.ReadLine();
                        //strs = str.Split(new char[] { ' ' });
                        lstdata.Add(str);
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(lstdata, N);
                    Console.WriteLine(sres);
                    sw.WriteLine(sres);
                }
            } catch (Exception ex) {
                Console.WriteLine(ex.Message);
            } finally {
                if (sr != null)
                    sr.Close();
                if (sw != null)
                    sw.Close();
            }

            return;
        }
    }

    public class prob {
        static long modul = 1000000007;

        public static string Solve(List<string> strs, int N) {
            List<int> svrs = new List<int>();
            for (int i = 0; i < strs.Count; i++) {
                svrs.Add(0);
            }

            int max = 0;
            long cnt = 0;
            do {
                List<Dictionary<string, int>> dsvr = new List<Dictionary<string, int>>();
                for (int i = 0; i < N; i++) {
                    dsvr.Add(new Dictionary<string, int>());
                }
                for (int i = 0; i < svrs.Count; i++) {
                    int svr = svrs[i];
                    string str = strs[i];
                    Dictionary<string, int> dic = dsvr[svr];
                    for (int ilen = 0; ilen <= str.Length; ilen++) {
                        if (!dic.ContainsKey(str.Substring(0, ilen))) {
                            dic.Add(str.Substring(0, ilen), 1);
                        }
                    }
                }

                int itrie = 0;
                foreach (Dictionary<string, int> dic in dsvr) {
                    itrie += dic.Count;
                }

                if (itrie > max) {
                    max = itrie;
                    cnt = 1;
                } else if (itrie == max) {
                    Math.DivRem((cnt + 1), modul, out cnt); 
                }
            } while (GetNext(ref svrs, N));

            return max.ToString() + " " + cnt.ToString();
        }

        public static bool GetNext(ref List<int> crr, int N) {
            bool ret = true;
            for (int i = 0; i < crr.Count; i++) {
                crr[i]++;
                if (crr[i] >= N) {
                    crr[i] = 0;
                    if (i == crr.Count - 1)
                        ret = false;
                } else {
                    break;
                }
            }

            return ret;
        }
    }
}
