package round3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class A {
    private static final String I_DONT_KNOW = "I don't know.";

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(A.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(A.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new A().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int d = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[k];
        for (int i = 0; i < k; i++) {
            a[i] = in.nextInt();
        }
        if (k == 1) return I_DONT_KNOW;
        int max = 1;
        for (int i = 0; i < d; i++) {
            max *= 10;
        }
        int[] z = new int[max];
        Arrays.fill(z, -1);
        for (int i = 0; i < k; i++) {
            if (z[a[i]] >= 0) {
                int p = i - z[a[i]];
                return "" + a[k - p];
            }
            z[a[i]] = i;
        }
        if (k == 2) {
            System.out.println(d + " " + Arrays.toString(a));
            return I_DONT_KNOW;
        }
        boolean[] pr = new boolean[max];
        Arrays.fill(pr, true);
        for (int i = 2; i < pr.length; i++) {
            if (i * i > pr.length) break;
            if (pr[i]) {
                for (int j = i * i; j < pr.length; j += i) pr[j] = false;
            }
        }
        long res = -1;
        for (long p = 2; p < pr.length; p++) {
            if (pr[((int) p)]) {
                boolean ok = true;
                for (int i = 0; i < a.length; i++) {
                    if (a[i] >= p) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) continue;

                long xx = a[1] - a[2];
                long yy = a[0] - a[1];
                xx = (xx + p) % p;
                yy = (yy + p) % p;

                long aa = ((BigInteger.valueOf(yy).modInverse(BigInteger.valueOf(p)).longValue()) * xx) % p;
                long bb = a[1] - a[0] * aa;
                bb = ((bb % p) + p ) % p;

                for (int i = 1; i < k; i++) {
                    long zz = (a[i - 1] * aa + bb) % p;
                    if (a[i] != zz) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) continue;
                long r = ((a[k - 1] * aa) + bb) % p;
                if (res >= 0 && res != r) return I_DONT_KNOW;
                res = r;
            }
        }
        if (res == -1) throw new Error();
        return "" + res;
    }
}