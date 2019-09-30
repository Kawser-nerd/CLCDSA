import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author mikit
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CBoxesAndCandies solver = new CBoxesAndCandies();
        solver.solve(1, in, out);
        out.close();
    }

    static class CBoxesAndCandies {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt(), x = in.nextInt();
            long sum = 0;
            int prev = 0;
            long ans = 0;
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                sum += a;
                if (sum > x) {
                    //System.out.println(sum - x + " " + sum);
                    a -= sum - x;
                    ans += sum - x;
                    sum = x;
                } else {
                    //System.out.println(0 + " " + sum);
                }
                sum -= prev;
                prev = a;
            }
            out.println(ans);
        }

    }
}