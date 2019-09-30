import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.function.DoubleUnaryOperator;

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
        D1 solver = new D1();
        solver.solve(1, in, out);
        out.close();
    }

    static class D1 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
            DoubleUnaryOperator calc = t -> a * t + b * Math.sin(c * t * Math.PI);
            double min = 0.0, max = 128.0;
            while (max - min > 1e-12) {
                double mid = (min + max) / 2.0;
                if (calc.applyAsDouble(mid) > 100) {
                    max = mid;
                } else {
                    min = mid;
                }
            }
            out.println(max);
        }

    }
}