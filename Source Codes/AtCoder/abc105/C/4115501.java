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
        ABC105_C solver = new ABC105_C();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC105_C {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            // TODO:Unsolve
            long n = in.nextLong();
            StringBuffer sb = new StringBuffer();

            while (true) {
                if (n % 2 != 0) {
                    sb.append(1);
                    n--;
                } else {
                    sb.append(0);
                }
                if (n == 0) {
                    break;
                } else {
                    n /= -2;
                }
            }

            out.print(sb.reverse().toString());


        }

    }
}