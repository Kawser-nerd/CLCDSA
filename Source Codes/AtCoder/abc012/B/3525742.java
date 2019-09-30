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
        ABC_012_B solver = new ABC_012_B();
        solver.solve(1, in, out);
        out.close();
    }

    static class ABC_012_B {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            int n = in.nextInt();
            int hour = 0;
            int minute = 0;
            int second = 0;
            while (n >= 3600) {
                hour++;
                n -= 3600;
            }

            while (n >= 60) {
                minute++;
                n -= 60;
            }
            second = n;
            out.print(String.format("%02d", hour) + ":" + String.format("%02d", minute) + ":" + String.format("%02d", second));

        }

    }
}