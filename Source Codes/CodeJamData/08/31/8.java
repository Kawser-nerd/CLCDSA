package indy.codejam;

import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;
import java.math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Math.*;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;
import static java.lang.Long.parseLong;
import static java.lang.Integer.parseInt;

public class TextMessagingOutrage {

    public static void main(String[] args) throws Exception {
        String name = "A-large";
        String path = "C:/codejam/";
        Scanner sc = new Scanner(new File(path + name + ".in"));
        PrintWriter pw = new PrintWriter(path + name + ".out");
        int N = sc.nextInt();
        for (int z = 1; z <= N; z++) {
            int P = sc.nextInt();
            int K = sc.nextInt();
            int L = sc.nextInt();
            long[] f = new long[L];
            for (int i = 0; i < L; i++) {
                f[i] = sc.nextLong();
            }
            sort(f);

            long res = 0;
            for (int i = 0; i < L; i++) {
                long r = i / K + 1;
                res += f[L - 1 - i] * r;
            }

            pw.print("Case #" + z + ": " + res);
            pw.println();
            pw.flush();
        }
        pw.close();
    }
}
