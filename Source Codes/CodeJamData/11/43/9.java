import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("input.txt"));
        PrintWriter out = new PrintWriter("output.txt");
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + new C().solve(in);
            out.println(s);
            System.out.println(s);
        }
        out.close();
    }

    private String solve(Scanner in) {
        long N = in.nextLong();
        int m = 0;
        while (1l * m * m <= N) m++;
        boolean[] p = new boolean[m];
        Arrays.fill(p, true);

        int res = 0;
        for (int x = 2; x < m; x++) {
            if (p[x]) {
                for (int y = x + x; y < m; y += x) {
                    p[y] = false;
                }
                int t = 0;
                long n = N;
                while (n >= x) {
                    n /= x;
                    t++;
                }
                res += t - 1;
            }
        }
        if (N > 1) res++;
        return "" + res;
    }
}