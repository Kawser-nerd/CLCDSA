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
                    int N = int.Parse(str);

                    List<train> trains = new List<train>();
                    str = sr.ReadLine();
                    strs = str.Split(new char[] { ' ' });
                    for (int i = 0; i < N; i++) {
                        trains.Add(new train(strs[i]));
                    }

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");

                    string sres = prob.Solve(trains);
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

    public class train {
        //public string tstr;
        public char cb;
        public char ce;
        public int ways;
        public List<char> ccnt;
        public List<char> cmid;
        //bool flg;
        public train() {
            ccnt = new List<char>();
            cmid = new List<char>();
            ways = 0;
        }
        public train(string str) {
            ccnt = new List<char>();
            cmid = new List<char>();

            //tstr = str;
            ways = 1;
            char[] chs = str.ToCharArray(0, str.Length);
            foreach (char ch in chs) {
                if (!ccnt.Contains(ch))
                    ccnt.Add(ch);
            }

            cb = chs[0];
            ce = chs[chs.Length - 1];
            int ib = chs.Length;
            for (int i = 1; i < chs.Length - 1; i++) {
                if (chs[i] != cb) {
                    ib = i;
                    break;
                }
            }
            int ie = 0;
            for (int i = chs.Length - 2; i > 0; i--) {
                if (chs[i] != ce) {
                    ie = i;
                    break;
                }
            }
            for (int i = ib; i <= ie; i++) {
                if (!cmid.Contains(chs[i])) {
                    cmid.Add(chs[i]);
                }
            }

            foreach (char ch in ccnt) {
                int stt = str.IndexOf(ch);
                int end = str.LastIndexOf(ch);
                for (int i = stt + 1; i < end; i++) {
                    if (chs[i] != ch) {
                        ways = 0;
                        break;
                    }
                }
                if (ways == 0)
                    break;
            }
        }
    }

    public class prob {
        public static int mdl = 1000000007;

        public static string Solve(List<train> trains) {
            List<char> chs = new List<char>();
            for (int i = 0; i < trains.Count; i++) {
                if (trains[i].ways == 0)
                    return "0";

                foreach (char mch in trains[i].cmid) {
                    for (int j = 0; j < trains.Count; j++) {
                        if (i == j)
                            continue;

                        if (trains[j].ccnt.Contains(mch))
                            return "0";
                    }
                }

                foreach (char ch in trains[i].ccnt) {
                    if (!chs.Contains(ch))
                        chs.Add(ch);
                }
            }

            foreach (char ch in chs) {
                List<train> ttrs = trains.FindAll(t => t.ccnt.Contains(ch));
                train ntr = Merge(ttrs, ch);
                if (ntr.ways == 0)
                    return "0";

                foreach (train tr in ttrs)
                    trains.Remove(tr);
                trains.Add(ntr);
            }

            int iw = 1;
            int iwc = trains.Count;
            while (iwc > 1) {
                //iw = (iw * iwc) % mdl;
                iw = (int)(Math.BigMul(iw, iwc) % mdl);
                iwc--;
            }
            foreach (train tr in trains) {
                iw = (int)(Math.BigMul(iw, tr.ways) % mdl);
                //iw = (iw * tr.ways) % mdl;
            }

            return iw.ToString();
        }

        private static train Merge(List<train> ttrs, char ch) {
            train ntr = new train();
            int ibc = 0, iec = 0;
            foreach (train tr in ttrs) {
                if (tr.cb != ch) {
                    ibc++;
                    ntr.cb = tr.cb;
                }
                if (tr.ce != ch) {
                    iec++;
                    ntr.ce = tr.ce;
                }
                foreach (char cch in tr.ccnt) {
                    if (!ntr.ccnt.Contains(cch)) {
                        ntr.ccnt.Add(cch);
                    }
                }
                foreach (char mch in tr.cmid) {
                    if (!ntr.cmid.Contains(mch)) {
                        ntr.cmid.Add(mch);
                    }
                }
            }

            if (ibc > 1 || iec > 1) {
                return ntr;
            }

            if (ibc == 1 && iec == 1 && ntr.cb == ntr.ce) {
                return ntr;
            }

            int iwc = ttrs.Count - 2;
            int iw = 1;

            if (ibc == 0) {
                ntr.cb = ch;
                iwc++;
            }
            if (iec == 0) {
                ntr.ce = ch;
                iwc++;
            }

            while (iwc > 1) {
                iw = (int)(Math.BigMul(iw, iwc) % mdl);
                iwc--;
            }

            foreach (train tr in ttrs) {
                iw = (int)(Math.BigMul(iw, tr.ways) % mdl);
            }

            ntr.ways = iw;

            return ntr;
        }
    }
}
