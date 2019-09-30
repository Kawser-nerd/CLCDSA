package google.codejam2013.round1b;

import java.io.*;
import java.util.Arrays;
import java.util.Locale;

public class FallingDiamonds {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));

    FallingDiamonds() throws IOException {
        reader = new BufferedReader(new FileReader("B-small-attempt1.in"));
        writer = new PrintWriter(new FileWriter("B-small-attempt1.out"));
    }

    int[] readInts() throws IOException {
        String line = reader.readLine();
        String []s = line.split(" ");
        int[] ret = new int[s.length];
        for(int i = 0; i < s.length; i++) {
            ret[i] = Integer.parseInt(s[i]);
        }
        return ret;
    }

    int[] tt = null;
    int ti = 0;
    int readInt() throws IOException {
        if(tt == null || ti == tt.length) {
            tt = readInts();
            ti = 0;
        }
        return tt[ti++];
    }



    void solveTest(int test) throws IOException {
        writer.printf("Case #%d:", test);
        int n = readInt();
        int level = 1;
        int q = 1;
        while(q <= n) {
            q += 4 * level + 1;
            level++;
        }
        level--;
        n -= level * (2 * level - 1);
        int x = readInt();
        int y = readInt();
        if(y < x + 2 * level - 1 && y < -x + 2 * level - 1) {
            writer.println(" 1.0");
            return;
        }
        if(y > x + 2 * (level + 1) - 1 || y > -x + 2 * (level + 1) - 1) {
            writer.println(" 0.0");
            return;
        }
        double[] f = new double[n + 1];
        f[0] = 1.0;
        for(int i = 1; i <= n; i++) {
            f[i] = f[i - 1] * i;
        }
        double p = 0.0;
        for(int i = 0; i <= n; i++) {
            int cnt = i + Math.max(0, n - i - 2 * level);
            cnt = Math.min(cnt, 2 * level);
            if(cnt >= y + 1) {
                p += f[n] / (f[i] * f[n - i]);
            }
        }
        double s = 1;
        for(int i = 0; i < n; i++) s *= 2;
        writer.printf(" %.10f\n", p / s);
    }

    void solve() throws IOException {
        Locale.setDefault(Locale.US);
        int t = readInt();
        for(int i = 1; i <= t; i++) {
            solveTest(i);
        }
        writer.flush();
    }

    public static void main(String[] args) throws IOException {
        new FallingDiamonds().solve();
    }
}
