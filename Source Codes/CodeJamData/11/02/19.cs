using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GoogleCodeJam {
    class Magicka {
        public void gen(StreamWriter sw, StreamReader sr) {
            char[,] combine = new char[26, 26];
            bool[,] opposite = new bool[26, 26];
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    combine[i, j] = ' ';
            string[] lines = sr.ReadLine().Split(new char[] { ' ' });
            int l = 0;
            int C = Convert.ToInt32(lines[l++]);
            for (int i = 0; i < C; i++, l++) {
                int a = convert_c2i(lines[l][0]);
                int b = convert_c2i(lines[l][1]);
                combine[a, b] = lines[l][2];
                combine[b, a] = lines[l][2];
            }
            int D = Convert.ToInt32(lines[l++]);
            for (int i = 0; i < D; i++, l++) {
                int a = convert_c2i(lines[l][0]);
                int b = convert_c2i(lines[l][1]);
                opposite[a, b] = true;
                opposite[b, a] = true;
            }
            int N = Convert.ToInt32(lines[l++]);
            string res = "";
            for (int i = 0; i < N; i++) {
                res = res + lines[l][i];
                while (res.Length >= 2) {
                    int a = convert_c2i(res[res.Length - 2]);
                    int b = convert_c2i(res[res.Length - 1]);
                    if (combine[a, b] != ' ')
                        res = res.Substring(0, res.Length - 2) + combine[a, b];
                    else
                        break;
                }
                if (res.Length >= 2) {
                    int a = convert_c2i(res[res.Length - 1]);
                    for (int j = 0; j < res.Length - 1; j++)
                        if (opposite[a, convert_c2i(res[j])]) {
                            res = "";
                            break;
                        }
                }
            }
            sw.Write("[");
            if (res.Length > 0)
                sw.Write(res[0]);
            for (int i = 1; i < res.Length; i++)
                sw.Write(", {0}", res[i]);
            sw.WriteLine("]");
        }
        private int convert_c2i(char c) {
            return (int)(c - 'A');
        }
    }
}
