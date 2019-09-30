package round3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(B.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(B.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        long l = in.nextLong();
        int n = in.nextInt();
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        Arrays.sort(b);
        int k = b[n - 1];
        if (l % k == 0) return "" + l / k;
        long[] d = new long[(int) k];
        Arrays.fill(d, -1);
        d[0] = (l / k);
        int[] q = new int[(int) k * 2];
        int h = 0;
        int t = 1;
        q[0] = 0;
        while (t != h) {
            int x = q[h];
            //System.out.println(x + " " + d[x]);
            h++;
            if (h == q.length) h = 0;
            for (int i = 0; i < n - 1; i++) {
                int y = x + b[i];
                int dd = 1;
                if (y >= k) {
                    y -= k;
                    dd = 0;
                }
                if ((d[y] == -1) || (d[y] > (d[x] + dd))) {
                    d[y] = d[x] + dd;
                    if (dd == 0) {
                        h--;
                        if (h < 0) h += q.length;
                        q[h] = y;
                    } else {
                        q[t] = y;
                        t++;
                        if (t == q.length) t = 0;
                    }
                }
            }
        }
        if (d[((int) (l % k))] == -1) return "IMPOSSIBLE";
        else return "" + d[((int) (l % k))];
    }
}