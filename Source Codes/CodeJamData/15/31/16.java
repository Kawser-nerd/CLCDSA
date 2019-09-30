/**
 * Created by wei on 4/11/15.
 */
import java.io.*;
import java.util.*;


public class SolutionA {
    static Scanner scanner = new Scanner (System.in);
    static PrintStream out = System.out;

    private static void solve() {
        long R = scanner.nextLong(), C = scanner.nextLong(), W = scanner.nextLong();

        long ans = (R - 1) * C;

        if (C % W == 0) {
            out.println (ans + C/W - 1 + W);
        } else {
            out.println (ans + C/W + W);
        }

    }


    public static void main(String[] args) {
        long T = Long.valueOf(scanner.next());

        for (long i = 1; i <= T; ++i) {
            System.out.print("Case #" + i + ": ");
            solve();
        }

    }
}
