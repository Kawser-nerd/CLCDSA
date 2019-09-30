using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB {
    class Program {
        struct jobT {
            public int s;
            public int e;
        }

        struct freeT {
            public int s;
            public int e;
        }

        static void Main(string[] args) {
            int T;
            int AC, AJ;
            string[] tokens;
            jobT[] jC;
            jobT[] jJ;
            List<int> freeC;
            List<int> freeJ;

            int c, j;
            bool isC, firstIsC;
            int change;
            int totJobC;
            int totJobJ;


            //string ioPath = @"D:\Aleaimo\Downloads\input";
            //string ioPath = @"D:\Aleaimo\Downloads\B-small-attempt0";
            string ioPath = @"D:\Aleaimo\Downloads\B-large";

            StreamReader sr = new StreamReader(ioPath + ".in");
            StreamWriter sw = new StreamWriter(ioPath + ".out", true);


            T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++) {
                tokens = sr.ReadLine().Split(' ');
                AC = int.Parse(tokens[0]);
                AJ = int.Parse(tokens[1]);

                jC = new jobT[AC];
                jJ = new jobT[AJ];
                totJobC = 0;
                totJobJ = 0;
                freeC = new List<int>();
                freeJ = new List<int>();
                
                for (int ac = 0; ac < AC; ac++) {
                    tokens = sr.ReadLine().Split(' ');
                    jC[ac].s = int.Parse(tokens[0]);
                    jC[ac].e = int.Parse(tokens[1]);
                    totJobC += (jC[ac].e - jC[ac].s);
                }
                for (int aj = 0; aj < AJ; aj++) {
                    tokens = sr.ReadLine().Split(' ');
                    jJ[aj].s = int.Parse(tokens[0]);
                    jJ[aj].e = int.Parse(tokens[1]);
                    totJobJ += (jJ[aj].e - jJ[aj].s);
                }

                Array.Sort<jobT>(jC, (x, y) => x.s.CompareTo(y.s));
                Array.Sort<jobT>(jJ, (x, y) => x.s.CompareTo(y.s));

                c = 0;
                j = 0;

                if (c < AC && j < AJ) {
                    if (jC[0].s < jJ[0].s) {
                        firstIsC = true;
                        c++;
                    }
                    else {
                        firstIsC = false;
                        j++;
                    }
                }
                else if (c < AC) {
                    firstIsC = true;
                    c++;
                } else {
                    firstIsC = false;
                    j++;
                }

                isC = firstIsC;

                change = 0;

                for (int a = 1; a < AC + AJ; a++) {
                    if (c < AC && j < AJ) {
                        if (jC[c].s < jJ[j].s) {
                            if (isC) {
                                freeC.Add(jC[c].s - jC[c - 1].e);
                                totJobC += (jC[c].s - jC[c - 1].e);
                            } else {
                                isC = true;
                                change++;
                            }
                            c++;
                        } else {
                            if (isC) {
                                isC = false;
                                change++;
                            }
                            else {
                                freeJ.Add(jJ[j].s - jJ[j - 1].e);
                                totJobJ += (jJ[j].s - jJ[j - 1].e);
                            }
                            j++;
                        }
                    } else if (c < AC) {
                        if (isC) {
                            freeC.Add(jC[c].s - jC[c - 1].e);
                            totJobC += (jC[c].s - jC[c - 1].e);
                        }
                        else {
                            isC = true;
                            change++;
                        }
                        c++;
                    } else {
                        if (isC) {
                            isC = false;
                            change++;
                        }
                        else {
                            freeJ.Add(jJ[j].s - jJ[j - 1].e);
                            totJobJ += (jJ[j].s - jJ[j - 1].e);
                        }
                        j++;
                    }
                }

                if (firstIsC && isC) {
                    freeC.Add((1440 - jC[AC-1].e) + jC[0].s);
                    totJobC += ((1440 - jC[AC - 1].e) + jC[0].s);
                } else if (!firstIsC && !isC) {
                    freeJ.Add((1440 - jJ[AJ - 1].e) + jJ[0].s);
                    totJobJ += ((1440 - jJ[AJ - 1].e) + jJ[0].s);
                } else {
                    change++;
                }

                freeC.Sort();
                freeC.Reverse();
                freeJ.Sort();
                freeJ.Reverse();
                c = 0;
                j = 0;

                while (totJobC > 720 || totJobJ > 720) {
                    if(totJobC > 720) {
                        totJobC -= freeC[c];
                        c++;
                    } else {
                        totJobJ -= freeJ[j];
                        j++;
                    }
                    change++;
                    change++;
                }

                sw.WriteLine("Case #{0}: {1}", t + 1, change);
            }

            sw.Close();

        }
    }
}
