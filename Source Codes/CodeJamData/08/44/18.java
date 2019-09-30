/*
 * Copyright (C) 2008 TopCoder Inc., All Rights Reserved.
 */

import java.io.*;
import java.util.*;

import java.io.PrintWriter;

public class D {
    static final int INF = 1000000;

    PrintWriter out;
    Scanner in;

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream("d.out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("d.in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");
            int k = in.nextInt();
            String s = in.next();

            int ans = INF;
            int[] perm = new int[5];
            char[] buf = new char[s.length()];
            for (int i = 0; i < 5 * 5 * 5 * 5 * 5; ++i) {
                perm[0] = i % 5;
                perm[1] = (i / 5) % 5;
                perm[2] = (i / 5 / 5) % 5;
                perm[3] = (i / 5 / 5 / 5) % 5;
                perm[4] = i / 5 / 5 / 5 / 5;
                boolean ok = true;
                for (int j = 0; j < k; ++j) {
                    if (perm[j] >= k) {
                        ok = false;
                    }
                    for (int l = j + 1; l < k; ++l) {
                        if (perm[j] == perm[l]) {
                            ok = false;
                        }
                    }
                }
                if (!ok) {
                    continue;
                }
                s.getChars(0, s.length(), buf, 0);
                for (int j = 0; j < s.length(); ++j) {
                    buf[perm[j % k] + (j / k) * k] = s.charAt(j);
                }
                int x = 0;
                for (int j = 1; j < s.length(); ++j) {
                    if (buf[j] != buf[j - 1]) {
                        ++x;
                    }
                }
                ans = Math.min(ans, x);
            }

            out.println(ans + 1);
        }

        out.close();
    }

    public static void main(String[] args) throws Exception {
        new D().solve();
    }
}
