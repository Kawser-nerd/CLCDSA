using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;

class Problem {
    const string inFile = "..\\..\\alarge.in";
    const string outFile = "..\\..\\alarge.out";

    public void Process() {
        using (StreamReader sr = new StreamReader(inFile)) {
            using (StreamWriter sw = new StreamWriter(outFile)) {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++) {
                    int n = int.Parse(sr.ReadLine());
                    string[] s = new string[n];
                    for (int i = 0; i < n; i++) {
                        s[i] = sr.ReadLine();
                    }

                    string res = Solve(n, s);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    private string Solve(int n, string[] s) {
        double[] wp = new double[n];
        int[] win = new int[n];
        int[] total = new int[n];

        for (int i = 0; i < n; i++) {
            int _total = 0, _win = 0;
            for (int j = 0; j < n; j++) {
                if (s[i][j] == '1') {
                    _total++;
                    _win++;
                }
                else if (s[i][j] == '0') {
                    _total++;
                }
            }
            wp[i] = _win * 1.0 / _total;
            win[i] = _win;
            total[i] = _total;
        }

        double[] owp = new double[n];
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (s[i][j] != '.') {
                    int _win = win[j];
                    if (s[j][i] == '1') {
                        _win--;
                    }
                    double pc = _win * 1.0 / (total[j] - 1);

                    sum += pc;
                }
            }
            owp[i] = sum / total[i];
        }

        double[] oowp = new double[n];
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (s[i][j] != '.') {
                    sum += owp[j];
                }
            }
            oowp[i] = sum / total[i];
        }

        string ss = "";
        for (int i = 0; i < n; i++) {
            double k = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
            ss = ss + Environment.NewLine + k;
        }
        return ss;
    }

    public static void Main() {
        Problem p = new Problem();
        p.Process();
    }
}