
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
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
        long a = in.nextInt();
        int n = in.nextInt();
        long[] b = new long[n];
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        long res = Long.MAX_VALUE;
        long c = 0;
        Arrays.sort(b);
        for (int i = 0; i < n; i++) {
            res = Math.min(res, c + n - i);
            while (a <= b[i]) {
                if (a == 1) return "" + res;
                a += (a - 1);
                c++;
            }
            a += b[i];
//            System.out.println(a);
        }
        res = Math.min(res, c);
        return "" + res;
    }
}