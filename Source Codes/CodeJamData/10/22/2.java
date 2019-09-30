package round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            out.println("Case #" + (i + 1) + ": " + new B().solve(in));
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int k = in.nextInt();
        int b = in.nextInt();
        int t = in.nextInt();
        int[] x = new int[n];
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            v[i] = in.nextInt();
        }
        boolean[] z = new boolean[n];
        for (int i = 0; i < n; i++) {
            z[i] = x[i] + v[i] * t >= b;
        }
        int[] q = new int[n];
        int m = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (z[i]) {
                q[m++] = i;
            }
        }
        if (m < k) return "IMPOSSIBLE";
        int s = 0;
        for (int i = 0; i < k; i++) {
            int j = n - i - 1;
            s += (j - q[i]);
        }
        return "" + s;
    }
}