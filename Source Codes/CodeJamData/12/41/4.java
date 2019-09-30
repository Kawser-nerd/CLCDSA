
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

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
        int n = in.nextInt();
        int[] d = new int[n + 1];
        int[] l = new int[n + 1];
        for (int i = 0; i < n; i++) {
            d[i] = in.nextInt();
            l[i] = in.nextInt();
        }
        d[n] = in.nextInt();
        int[] z = new int[n + 1];
        z[0] = d[0];
        for (int i = 0; i < n; i++) {
            z[i] = Math.min(z[i], l[i]);
            for (int j = i + 1; j <= n; j++) {
                if (d[j] <= d[i] + z[i]) {
                    z[j] = Math.max(z[j], d[j] - d[i]);
                }
            }
        }
        return z[n] > 0 ? "YES" : "NO";
    }
}