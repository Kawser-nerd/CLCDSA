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
                    int K = int.Parse(strs[0]);
                    int L = int.Parse(strs[1]);
                    int S = int.Parse(strs[2]);

                    //List<int> lstdata = new List<int>();
                    //str = sr.ReadLine();
                    //strs = str.Split(new char[] { ' ' });
                    //for (int i = 0; i < D; i++) {
                    //    lstdata.Add(int.Parse(strs[i]));
                    //}
                    string str1 = sr.ReadLine();
                    string str2 = sr.ReadLine();

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(str1, str2, S);
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

        public static string Solve(String ks, String ls, int S) {
            int icnt = 0;
            double dprob = 0.0;

            foreach (char c in ls.ToCharArray()) {
                if (!ks.Contains(c)) {
                    return dprob.ToString("##0.0#####");
                }
            }

            if(ls.Length > S)
                return dprob.ToString("##0.0#####");

            int lsm = 0;
            for (int i = 1; i < ls.Length; i++) {
                bool bm = true;
                for (int j = i; j < ls.Length; j++) {
                    if (ls[j] != ls[j - i]) {
                        bm = false;
                        break;
                    }
                }
                if (bm) {
                    lsm = i;
                    break;
                }
            }

            double dmax = 0.0;
            if (lsm == 0) {
                dmax = (S / ls.Length);
            } else {
                dmax = 1 + ((S - ls.Length) / lsm);
            }

            Dictionary<char, int> dick = new Dictionary<char, int>();
            foreach (char c in ks.ToCharArray()) {
                if (dick.ContainsKey(c)) {
                    dick[c] += 1;
                } else {
                    dick.Add(c, 1);
                }
            }

            double dkl = (double)ks.Length;
            dprob = 1.0;

            foreach (char c in ls.ToCharArray()) {
                dprob *= (double)dick[c] / dkl;
            }

            dprob *= (double)(S - ls.Length + 1);
            
            
            return (dmax - dprob).ToString("##0.0#####");
            //return (icnt).ToString();
        }


    }
}
