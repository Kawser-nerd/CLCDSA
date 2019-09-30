import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        ABC096_A solver = new ABC096_A();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC096_A {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int a = in.nextInt();
            int b = in.nextInt();

            int ans = a;

            if (a <= b) {
                out.print(ans);
            } else {
                out.print(ans - 1);
            }
        }

    }
}