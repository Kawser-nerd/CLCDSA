using System;
using System.Collections.Generic;
public class Aprob {
    public static void Main() {
        string[] alph = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
        string[] readSome = new string[2];
        readSome = Console.ReadLine().Split(' ');
        int N = int.Parse(readSome[0]);
        int K = int.Parse(readSome[1]);
        string S = Console.ReadLine();
        string[] Ss = new string[N];
        for (int i = 0; i < N; i++) {
            Ss[i] = S.Substring(i, 1);
        }
        Array.Sort(Ss);
        string T = "";
        int notsame = 0;
        int n = 0;
        int m = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N;k++) {
                if (Ss[k] != "0") {
                    notsame = 0;
                    if (Ss[k] != S.Substring(i, 1)) {
                        notsame++;
                    }
                    for (int j = 0; j < i; j++) {
                        if (T.Substring(j, 1) != S.Substring(j, 1)){
                            notsame++;
                        }
                    }
                    x = 0;
                    y = 0;
                    foreach (string alpha in alph) {
                        n = 0;
                        m = 0;
                        for (int j = i + 1; j < N; j++) {
                            if (S.Substring(j, 1) == alpha) {
                                n++;
                            }
                        }
                        for (int j = 0; j < N; j++) {
                            if (Ss[j] == alpha & j != k) {
                                m++;
                            }
                        }
                        if (n - m > 0) {
                            x += n - m;
                        } else {
                            y += m - n;
                        }
                    }
                    notsame += (Math.Min(x, y) + Math.Abs(x - y));
                    if (notsame <= K) {
                        T += Ss[k];
                        Ss[k] = "0";
                        break;
                    }
                }
            }
        }
        Console.WriteLine(T);
    }
}