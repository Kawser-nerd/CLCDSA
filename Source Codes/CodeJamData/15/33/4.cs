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
                    int C = int.Parse(strs[0]);
                    int D = int.Parse(strs[1]);
                    int V = int.Parse(strs[2]);

                    List<int> lstdata = new List<int>();
                    str = sr.ReadLine();
                    strs = str.Split(new char[] { ' ' });
                    for (int i = 0; i < D; i++) {
                        lstdata.Add(int.Parse(strs[i]));
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(C, D, V, lstdata);
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

        public static string Solve(int C, int D, int V, List<int> lstd) {
            int icnt = 0;

            if (C == 1) {
                if (!lstd.Contains(1)) {
                    icnt++;
                    lstd.Add(1);
                }
                if (V > 1 && !lstd.Contains(2)) {
                    icnt++;
                    lstd.Add(2);
                }
                while (true) {
                    List<int> lstv = new List<int>();
                    List<int> lstvadd = new List<int>();
                    for (int i = 0; i <= V; i++) {
                        lstv.Add(0);
                        if (i == 0 || lstd.Contains(i))
                            lstvadd.Add(0);
                        else
                            lstvadd.Add(1);
                    }
                    lstv[0] = 1;

                    foreach (int id in lstd) {
                        List<int> lstabit = new List<int>();
                        for (int i = 0; i < V; i++) {
                            if (lstv[i] == 1 && i + id <= V) {
                                //lstv[i + id] = 1;
                                lstabit.Add(i + id);
                            }
                        }
                        foreach (int ib in lstabit) {
                            lstv[ib] = 1;
                        }
                    }

                    bool bcomp = true;
                    for (int i = 0; i <= V; i++) {
                        if (lstv[i] == 0) {
                            bcomp = false;

                            for (int j = 3; j <= i; j++) {
                                if (lstv[i - j] == 1 && lstvadd[j] > 0) {
                                    lstvadd[j]++;
                                }
                            }
                        }
                    }

                    if (bcomp) {
                        break;
                    } else {
                        int idadd=1;
                        int iaddmax = 1;

                        for (int i = 0; i < lstvadd.Count; i++) {
                            if (lstvadd[i] > iaddmax) {
                                idadd = i;
                                iaddmax = lstvadd[i];
                            }
                        }

                        lstd.Add(idadd);
                        icnt++;
                    }
                }

            } else {
            }

            return (icnt).ToString();
        }


    }
}
