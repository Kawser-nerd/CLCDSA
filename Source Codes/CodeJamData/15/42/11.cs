using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

class ProblemA {
    static string inputFileName = "../../input.txt";
    static string outputFileName = "../../output.txt";
    static StreamReader fileReader;
    static StreamWriter file;
    static string[] inputTokens;
    static int curInputTokenIndex;
    static string NextToken() {
        if (file == null) {
            file = new StreamWriter(outputFileName, false);
        }
        string ret = "";
        while (ret == "") {
            if (inputTokens == null || curInputTokenIndex >= inputTokens.Length) {
                string line;
                if (Type.GetType("HaitaoLocal") != null) {
                    if (fileReader == null) {
                        fileReader = new StreamReader(inputFileName);
                    }
                    line = fileReader.ReadLine();
                    if (line == null) {
                        throw new Exception("Error: out of input tokens!");
                    }
                } else {
                    line = Console.ReadLine();
                }
                inputTokens = line.Split();
                curInputTokenIndex = 0;
            }
            ret = inputTokens[curInputTokenIndex++];
        }
        return ret;
    }
    static int ReadInt() {
        return Int32.Parse(NextToken());
    }
    static string ReadString() {
        return NextToken();
    }
    static long ReadLong() {
        return Int64.Parse(NextToken());
    }
    static int[] ReadIntArray(int length) {
        int[] ret = new int[length];
        for (int i = 0; i < length; i++) {
            ret[i] = ReadInt();
        }
        return ret;
    }
    static string[] ReadStringArray(int length) {
        string[] ret = new string[length];
        for (int i = 0; i < length; i++) {
            ret[i] = ReadString();
        }
        return ret;
    }
    static long[] ReadLongArray(int length) {
        long[] ret = new long[length];
        for (int i = 0; i < length; i++) {
            ret[i] = ReadLong();
        }
        return ret;
    }
    static string DoubleToString(double d) {
        return d.ToString(new CultureInfo("en-US"));
    }

    public static void Main(string[] args) {
        int T = ReadInt();
        for (int m = 0; m < T; m++) {

            int R = ReadInt();
            int C = ReadInt();
            char[,] ar = new char[R,C];
            for(int r=0; r<R; r++) {
                string s = ReadString();
                for(int c=0; c<C; c++) {
                    ar[r,c] = s[c];
                }
            }
            bool possible = true;
            int change = 0;
            int[] dr = new int[] {-1,0,1,0};
            int[] dc = new int[] {0,-1,0,1};
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (ar[r, c] == '.') continue;
                    int d = 0;
                    if (ar[r, c] == '^') { d = 0; }
                    if (ar[r, c] == '<') { d = 1; }
                    if (ar[r, c] == 'v') { d = 2; }
                    if (ar[r, c] == '>') { d = 3; }
                    int rr = r;
                    int cc = c;
                    bool works = false;
                    while(true) {
                        rr += dr[d];
                        cc += dc[d];
                        if (rr >= R || cc >= C || rr < 0 || cc < 0) {
                            break;
                        }
                        if (ar[rr, cc] != '.') {
                            works = true;
                            break;
                        }
                    }
                    if (works) continue;
                    bool good = false;
                    for (int dd = 0; dd < 4; dd++) {
                        if (dd == d) continue;
                        rr = r;
                        cc = c;
                        works = false;
                        while (true) {
                            rr += dr[dd];
                            cc += dc[dd];
                            if (rr >= R || cc >= C || rr < 0 || cc < 0) {
                                break;
                            }
                            if (ar[rr, cc] != '.') {
                                works = true;
                                break;
                            }
                        }
                        if (works) {
                            good = true;
                        }
                    }
                    if (!good) possible = false;
                    else {
                        change++;
                    }
                }
            }

            file.WriteLine("Case #" + (m+1) + ": " + (possible ? ("" + change) : "IMPOSSIBLE"));
        }
        file.WriteLine();
        file.Close();
    }

        



}
