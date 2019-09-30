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
            long N = ReadLong();

            long P = 1;
            long ans = 0;
            for (int d = 1; d <= 16; d++) {
                P *= 10;
                if (N >= P) {
                    if (d == 1) ans += 10;
                    else {
                        int h = d / 2;
                        long HP = 1;
                        for (int i = 0; i < h; i++) HP *= 10;
                        if (d % 2 == 0) {
                            ans += HP * 2 - 1;
                        } else {
                            ans += HP * 11 - 1;
                        }
                    }
                } else {
                    if (d == 1) ans += N;
                    else {
                        int h = d / 2;
                        long HP = 1;
                        for (int i = 0; i < h; i++) HP *= 10;
                        long rev = Int64.Parse(String.Concat((N + "").Reverse()));
                        long a,b;
                        if (d % 2 == 0) {
                            a = N % HP;
                            b = rev % HP;
                            if (b == 1) {
                                ans += a + b - 1;
                            } else if (a == 0) {
                                N--;
                                rev = Int64.Parse(String.Concat((N + "").Reverse()));
                                a = N % HP;
                                b = rev % HP;
                                ans += a + b;
                                if (b == 1) ans--;
                                ans++;
                            } else {
                                ans += a + b;
                            }
                        } else {
                            a = N % (HP*10);
                            b = rev % HP;
                            if (b == 1) {
                                ans += a + b - 1;
                            } else if (a == 0) {
                                N--;
                                rev = Int64.Parse(String.Concat((N + "").Reverse()));
                                a = N % (HP * 10);
                                b = rev % HP;
                                ans += a + b;
                                if (b == 1) ans--;
                                ans++;
                            } else {
                                ans += a + b;
                            }
                        }
                    }
                    break;
                }
            }
            file.WriteLine("Case #"+(m+1)+": "+ans);
        }


        file.Close();
    }
}
