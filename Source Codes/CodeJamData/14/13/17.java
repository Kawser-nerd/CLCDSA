
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class C {

    private static double[][] p;

    public static void main(String[] args) throws FileNotFoundException {
        int n = 1000;
        p = new double[n][n];
        for (int i = 0; i < n; i++) {
            p[i][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (j != i) {
                for (int k = 0; k < n; k++) {
                    p[j][k] = p[j][k] * (n - 1) / n + p[i][k] / n;
                }
            }
            for (int k = 0; k < n; k++) {
                p[i][k] = 1.0 / n;
            }
        }
        Scanner in = new Scanner(new File(C.class.getSimpleName() + ".in"));
        PrintWriter out = new PrintWriter(new File(C.class.getSimpleName() + ".out"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    static Random random = new Random(114364675657867342L);

    private String solve(Scanner in) {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        double p1 = 0;
        double p2 = 0;
        for (int i = 0; i < n; i++) {
            p1 += Math.log(1.0 / n);
            p2 += Math.log(p[i][a[i]]);
        }
        System.out.println(p1 + " " + p2);
        if (p1 > p2) return "GOOD"; else return "BAD";
    }
}