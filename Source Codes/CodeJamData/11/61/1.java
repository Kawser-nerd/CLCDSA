import com.sun.media.sound.MidiOutDeviceProvider;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

    private static final long MOD = 1000003;

    private String solve(Scanner in) {
        String s = in.next();
        int[] num = new int[26];
        for (int i = 0; i < s.length(); i++) {
            num[s.charAt(i) - 'a']++;
        }
        int k = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) != s.charAt(i - 1)) k++;
        }
        long[] d = new long[k];
        long[] dd = new long[k];
        int c = 0;
        while (num[c] == 0) c++;
        d[0] = 1;
        int len = num[c];
        for (c = c + 1; c < num.length; c++) if (num[c] > 0) {
            Arrays.fill(dd, 0);
            for (int i = 0; i < k; i++) if (d[i] > 0) {
                for (int j = 1; i + j < k; j++) {
                    long r = c(num[c] - 1, j - 1);
                    if (r == 0) continue;
                    r *= d[i];
                    r %= MOD;
                    int p1 = i + 2;
                    int p2 = len - 1 - i;
                    for (int u = 0; u <= j; u++) if (i + j + (j - u) < k) {
                        long rr = r * c(p1, u);
                        rr %= MOD;
                        rr = rr * c(p2, j - u);
                        rr %= MOD;
                        if (rr == 0) continue;
                        dd[i + j + (j - u)] += rr;
                        dd[i + j + (j - u)] %= MOD;
                    }
                }
            }
            len += num[c];
            long[] t = d;
            d = dd;
            dd = t;
        }
        return "" + d[k - 1];
    }

    private static final int[][] C = new int[450001][200];
    static {
        for (int i = 0; i < C.length; i++) {
            C[i][0] = 1;
            if (i > 0) for (int j = 1; j < C[i].length; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                if (C[i][j] > 1000003) C[i][j] -= 1000003;
            }
        }
    }

    private long c(int n, int k) {
        if (k < 0 || k > n) return 0;
        return C[n][k];
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

}