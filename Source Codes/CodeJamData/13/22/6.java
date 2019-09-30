
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
            String s = "Case #" + (i + 1) + ": " + new B().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        int c = 1;
        int s = 1;
        int xx = 0;
        while (true) {
            c += 4;
            if (s + c > n) break;
            xx += 2;
            s += c;
        }
        if (Math.abs(x) + y <= xx) {
            return "1.0";
        }
//        System.out.println(s + " " + c + " " + xx);
        if (Math.abs(x) + y > xx + 2) {
            return "0.0";
        }
        int k = n - s;
        if (k == 0) return "0.0";
        int p = y + 1;

        double[][] d = new double[k + 1][k + 1];
        d[0][0] = 1;
        c /= 2;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= i; j++) {
                if (i + 1 - j <= c) {
                    d[i + 1][j] += d[i][j] * 0.5;
                } else {
                    d[i + 1][j + 1] += d[i][j] * 0.5;
                }
                if (j + 1 <= c) {
                    d[i + 1][j + 1] += d[i][j] * 0.5;
                } else {
                    d[i + 1][j] += d[i][j] * 0.5;
                }
            }
        }
        double res = 0;
        for (int i = p; i <= k; i++) {
            res += d[k][i];
        }

//        System.out.println(s + " " + c + " " + k + " " + p);
        if (res > 1) res = 1;
        return "" + res;
    }
}