using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;

class Problem {
    const string inFile = "..\\..\\bsmall.in";
    const string outFile = "..\\..\\bsmall.out";

    public void Process() {
        using (StreamReader sr = new StreamReader(inFile)) {
            using (StreamWriter sw = new StreamWriter(outFile)) {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++) {
                    int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                    int n = ss[0];
                    int D = ss[1];

                    int[] p = new int[n];
                    int[] v = new int[n];

                    for (int i = 0; i < n; i++) {
                        ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                        p[i] = ss[0];
                        v[i] = ss[1];
                    }

                    string res = Solve(n, D, p, v);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

    private string Solve(int n, int D, int[] p, int[] v) {

        double left = 0;
        double right = 1e12;
        for (int i = 0; i < 100; i++) {
            double middle = (left + right) / 2;
            if (ok(n, D, p, v, middle)) {
                right = middle;
            }
            else {
                left = middle;
            }
        }

        double res = (left + right) / 2;
        return res.ToString();
    }

    private bool ok(int n, int D, int[] p, int[] v, double time) {
        double current = double.MinValue;
        for (int i = 0; i < n; i++) {
            double leftMost = Math.Max(p[i] - time, current);
            double rightMost = leftMost + (v[i] - 1) * D;
            if (rightMost - p[i] > time) {
                return false;
            }
            else {
                current = rightMost + D;
            }
        }
        return true;
    }

    public static void Main() {
        Problem p = new Problem();
        p.Process();
    }
}