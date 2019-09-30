using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static void Main(string[] args) {
        var mod = 1000000007L;
        var maxD = mod * 100000L;
        var nm = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var st = Console.ReadLine().Split().Select(int.Parse).ToArray();
        var N = nm[0];
        var M = nm[1];
        var S = st[0] - 1;
        var T = st[1] - 1;

        var uv = new List<int>[N];
        var ud = new List<int>[N];
        for (int i = 0; i < N; i++) { uv[i] = new List<int>(); ud[i] = new List<int>(); }

        for (var i = 0; i < M; i++) {
            var uvdl = Console.ReadLine().Split(new char[] { ' ' }).Select(word => int.Parse(word)).ToList();
            var u = uvdl[0] - 1;
            var v = uvdl[1] - 1;
            var d = uvdl[2] * 2;
            uv[u].Add(v);
            ud[u].Add(d);
            uv[v].Add(u);
            ud[v].Add(d);
        }

        var DS = new long[N];
        var DT = new long[N];
        for (var i = 0; i < N; i++) {
            DS[i] = maxD;
            DT[i] = maxD;
        }
        DS[S] = 0;
        DT[T] = 0;

        var OS = new List<int>();
        var OT = new List<int>();
        var PK = new int[N];
        var FS = new long[N]; FS[S] = 1;
        var FT = new long[N]; FT[T] = 1;

        var QS1 = new int[M]; QS1[0] = S;
        var QS2 = new long[M]; QS2[0] = 0;
        int QSC = 0;
        var QT1 = new int[M]; QT1[0] = T;
        var QT2 = new long[M]; QT2[0] = 0;
        int QTC = 0;


        var pd = QS2[0];
        var rd = QT2[0];
        var f = true;

        while (f && QSC >= 0 && QTC >= 0) {
            if (pd <= rd) {
                while (QSC >= 0 && pd == QS2[0]) {
                    var p = QS1[0];
                    var q = QS1[QSC];
                    var d = QS2[QSC];
                    QSC--;
                    if (QSC >= 0) {
                        var j = 0; var i = 1;
                        while (i <= QSC) {
                            if (i < QSC && (QS2[i] > QS2[i + 1])) i++;
                            if (QS2[i] >= d) break;
                            QS1[j] = QS1[i];
                            QS2[j] = QS2[i];
                            j = i;
                            i = j * 2 + 1;
                        }
                        QS1[j] = q;
                        QS2[j] = d;
                    }
                    if (PK[p] == 2) { f = false; continue; }
                    if (pd > DS[p]) { continue; }
                    for (var x = 0; x < uv[p].Count; x++) {
                        q = uv[p][x];
                        d = ud[p][x] + pd;
                        if (DS[q] > d) {
                            DS[q] = d;
                            FS[q] = FS[p];
                            var j = QSC + 1;
                            while (j > 0) {
                                var i = (j - 1) / 2;
                                if (QS2[i] <= d) break;
                                QS1[j] = QS1[i];
                                QS2[j] = QS2[i];
                                j = i;
                            }
                            QS1[j] = q;
                            QS2[j] = d;
                            QSC++;
                        } else if (DS[q] == d) {
                            FS[q] = (FS[q] + FS[p]) % mod;
                        }
                    }
                    PK[p] = 1;
                    OS.Add(p);
                }
                pd = QS2[0];
            } else {
                while (QTC >= 0 && rd == QT2[0]) {
                    var r = QT1[0];
                    var q = QT1[QTC];
                    var d = QT2[QTC];
                    QTC--;
                    if (QTC >= 0) {
                        var j = 0; var i = 1;
                        while (i <= QTC) {
                            if (i < QTC && (QT2[i] > QT2[i + 1])) i++;
                            if (QT2[i] >= d) break;
                            QT1[j] = QT1[i];
                            QT2[j] = QT2[i];
                            j = i;
                            i = j * 2 + 1;
                        }
                        QT1[j] = q;
                        QT2[j] = d;
                    }
                    if (PK[r] == 1) { f = false; continue; }
                    if (rd > DT[r]) { continue; }
                    for (var x = 0; x < uv[r].Count; x++) {
                        q = uv[r][x];
                        d = ud[r][x] + rd;
                        if (DT[q] > d) {
                            DT[q] = d;
                            FT[q] = FT[r];
                            var j = QTC + 1;
                            while (j > 0) {
                                var i = (int)((j - 1) / 2);
                                if (QT2[i] <= d) { break; }
                                QT1[j] = QT1[i];
                                QT2[j] = QT2[i];
                                j = i;
                            }
                            QT1[j] = q;
                            QT2[j] = d;
                            QTC++;
                        } else if (DT[q] == d) {
                            FT[q] = (FT[q] + FT[r]) % mod;
                        }
                    }
                    PK[r] = 2;
                    OT.Add(r);
                }
                rd = QT2[0];
            }
        }

        var OS2 = new List<int>();
        long da = pd + rd;
        foreach (var p in OS) {
            if (DS[p] + DT[p] < da) {
                da = DS[p] + DT[p];
                OS2.Clear(); OS2.Add(p);
            } else if (DS[p] + DT[p] == da) {
                OS2.Add(p);
            }
        }
        var coltime = da / 2;

        long t = 0; long s = 0;
        foreach (var p in OS2) {
            if (DS[p] == coltime) {
                var v = (FS[p] * FT[p]) % mod;
                s = (s + v) % mod;
                t = (t + v * v) % mod;
            } else {
                for (var x = 0; x < uv[p].Count; x++) {
                    var q = uv[p][x];
                    if (PK[q] != 2) continue;
                    if (DS[q] + DT[q] != da) continue;
                    if (DS[p] + ud[p][x] != DS[q]) continue;
                    var v = (FS[p] * FT[q]) % mod;
                    s = (s + v) % mod;
                    t = (t + v * v) % mod;
                }
            }
        }

        t = (s * s + mod - t) % mod;
        Console.Write(t);
    }
}