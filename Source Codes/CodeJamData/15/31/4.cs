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
                    int R = int.Parse(strs[0]);
                    int C = int.Parse(strs[1]);
                    int N = int.Parse(strs[2]);

                    //List<int> lstdata = new List<int>();
                    //str = sr.ReadLine();
                    //strs = str.Split(new char[] { ' ' });
                    //for (int i = 0; i < B; i++) {
                    //    lstdata.Add(int.Parse(strs[i]));
                    //}

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(R, C, N);
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

        public static string Solve(int R, int C, int N) {
            int icnt = 0;

            if (N == 1)
                return (R * C).ToString();

            int iminhit = C / N;

            icnt += iminhit * R;

            if (C % N == 0) {
                icnt += N - 1;
            } else {
                icnt += N;
            }

            return (icnt).ToString();
        }


    }
}
