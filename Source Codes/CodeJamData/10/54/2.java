package round3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

    private int s;
    private boolean[][] z;
    private int d;

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File(D.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(D.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new D().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        d = in.nextInt();
        s = 0;
        z = new boolean[10][d];
        calc(n, 0);
        return "" + s;
    }

    private void calc(int n, int p) {
        if (n == 0) {
            s++;
            return;
        }
        for (int i = p + 1; i <= n; i++) {
            int j = i;
            int k = 0;
            boolean ok = true;
            while (j > 0) {
                if (z[k][j % d]) {
                    ok = false;
                    break;
                }
                j /= d;
                k++;
            }
            if (ok) {
                j = i;
                k = 0;
                while (j > 0) {
                    z[k][j % d] = true;
                    j /= d;
                    k++;
                }
                calc(n - i, i);
                j = i;
                k = 0;
                while (j > 0) {
                    z[k][j % d] = false;
                    j /= d;
                    k++;
                }
            }
        }
        //To change body of created methods use File | Settings | File Templates.
    }
}