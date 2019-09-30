using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

class ProblemC {
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
            int N = ReadInt();
            int ans = 0;
            int n2, n3;
            n2 = 2;
            n3 = R+C-4;
            //Console.WriteLine(n2+" "+n3);
            if (R == 1 || C == 1) {
                if (R != 1) {
                    int t = R;
                    R = C;
                    C = t;
                }
                if (C % 2 == 0) {
                    if (N <= C / 2) ans = 0;
                    else {
                        ans = 2*(N - C / 2)-1;
                    }
                } else {
                    if (N <= (C + 1) / 2) ans = 0;
                    else {
                        ans = 2 * (N - (C + 1) / 2);
                    }
                }
            } else if (R % 2 == 1 && C % 2 == 1) {
                n2 = 4;
                n3 = 2 * (R / 2 + C / 2 - 2);
                if (N <= R * C / 2 + 1) {
                    ans = 0;
                } else {
                    int rem = N - (R * C / 2);
                    if (rem <= 2) {
                        ans = rem * 3 - 3;
                    } else {
                        if (rem <= n2) {
                            ans = rem * 2;
                        } else if (rem <= n2 + n3) {
                            ans = n2 * 2 + (rem - n2) * 3;
                        } else {
                            ans = n2 * 2 + n3 * 3 + (rem - n2 - n3) * 4;
                        }
                    }
                }
            } else {
                if (N <= R * C / 2) {
                    ans = 0;
                } else {
                    int rem = N - (R * C / 2);
                    //Console.WriteLine(rem);
                    if (rem <= n2) {
                        ans = rem * 2;
                    } else if (rem <= n2 + n3) {
                        ans = n2 * 2 + (rem - n2) * 3;
                    } else {
                        ans = n2 * 2 + n3 * 3 + (rem - n2 - n3) * 4;
                    }
                }
            }

            file.WriteLine("Case #" + (m + 1) + ": " + ans);
        }


        file.Close();
    }
}
