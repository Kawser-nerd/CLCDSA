/*
 * Copyright (C) 2008 TopCoder Inc., All Rights Reserved.
 */

import java.io.PrintWriter;
import java.io.FileOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.util.Scanner;
import java.util.Locale;

public class A {
    static final int INF = 1000000;

    PrintWriter out;

    Scanner in;

    boolean[] changeable;

    boolean[] gateType; // true for 'and'

    int[] minTrue;

    int[] minFalse;

    void applyAnd(int i, int cost) {
        minTrue[i] = Math.min(minTrue[i], minTrue[2 * i + 1] + minTrue[2 * i + 2] + cost);
        minFalse[i] = Math.min(minFalse[i], minFalse[2 * i + 1] + minTrue[2 * i + 2] + cost);
        minFalse[i] = Math.min(minFalse[i], minTrue[2 * i + 1] + minFalse[2 * i + 2] + cost);
        minFalse[i] = Math.min(minFalse[i], minFalse[2 * i + 1] + minFalse[2 * i + 2] + cost);
    }


    void applyOr(int i, int cost) {
        minTrue[i] = Math.min(minTrue[i], minTrue[2 * i + 1] + minTrue[2 * i + 2] + cost);
        minTrue[i] = Math.min(minTrue[i], minFalse[2 * i + 1] + minTrue[2 * i + 2] + cost);
        minTrue[i] = Math.min(minTrue[i], minTrue[2 * i + 1] + minFalse[2 * i + 2] + cost);
        minFalse[i] = Math.min(minFalse[i], minFalse[2 * i + 1] + minFalse[2 * i + 2] + cost);
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream("a.out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("a.in"))));        

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");

            int m = in.nextInt();
            int v = in.nextInt();
            changeable = new boolean[m];
            gateType = new boolean[m];
            minTrue = new int[m];
            minFalse = new int[m];
            for (int i = 0; i < m; ++i) {
                minTrue[i] = INF;
                minFalse[i] = INF;
                if (2 * (i + 1) <= m) {
                    gateType[i] = in.nextInt() == 1;
                    changeable[i] = in.nextInt() == 1;
                } else {
                    if (in.nextInt() == 1) {
                        minTrue[i] = 0;
                    } else {
                        minFalse[i] = 0;
                    }
                }
            }

            for (int i = m - 1; i >= 0; --i) {
                if (2 * (i + 1) > m) {
                    continue;
                }
                if (gateType[i]) {
                    applyAnd(i, 0);
                    if (changeable[i]) {
                        applyOr(i, 1);
                    }
                } else {
                    applyOr(i, 0);
                    if (changeable[i]) {
                        applyAnd(i, 1);
                    }
                }
            }

            int ans;
            if (v == 1) {
                ans = minTrue[0];
            } else {
                ans = minFalse[0];
            }
            if (ans < INF) {
                out.println(ans);
            } else {
                out.println("IMPOSSIBLE");
            }
        }

        out.close();
    }

    public static void main(String[] args) throws Exception {
        new A().solve();
    }
}
