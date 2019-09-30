import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author acesine
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        C solver = new C();
        solver.solve(1, in, out);
        out.close();
    }

    static class C {
        private long maxOfThree(long A, long B, long C) {
            return Math.max(Math.max(A, B), C);
        }

        private long minOfThree(long A, long B, long C) {
            return Math.min(Math.min(A, B), C);
        }

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            long H = in.nextInt(), W = in.nextInt();
            long minDiff = H * W;
            for (long h = 0; h <= H; h++) {
                long A = h * W;
                long B = ((H - h) / 2) * W;
                long C = H * W - A - B;
                minDiff = Math.min(minDiff, maxOfThree(A, B, C) - minOfThree(A, B, C));
                B = (H - h) * (W / 2);
                C = H * W - A - B;
                minDiff = Math.min(minDiff, maxOfThree(A, B, C) - minOfThree(A, B, C));
            }
            for (int w = 0; w < W; w++) {
                long A = w * H;
                long B = ((W - w) / 2) * H;
                long C = H * W - A - B;
                minDiff = Math.min(minDiff, maxOfThree(A, B, C) - minOfThree(A, B, C));
                B = (W - w) * (H / 2);
                C = H * W - A - B;
                minDiff = Math.min(minDiff, maxOfThree(A, B, C) - minOfThree(A, B, C));
            }
            out.println(minDiff);
        }

    }
}