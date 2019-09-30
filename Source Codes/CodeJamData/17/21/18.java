package Y2017.r1b;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

/**
 * Created by david on 22/04/17.
 */
public class CruiseControl {
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        try (PrintWriter writer = new PrintWriter("solution.txt", "UTF-8")) {
            for (int i = 1; i <= n; ++i) {
                writer.print(String.format("Case #%d: ", i));
                solve(scanner, writer);
            }
        }
    }

    public static void solve(Scanner scanner, PrintWriter writer) {
        int D = scanner.nextInt();
        int N = scanner.nextInt();
        double duration = 0;
        for(int i = 0; i < N; ++i) {
            int K = scanner.nextInt();
            int S = scanner.nextInt();
            double d = (D-K)/((double) S);
            duration = Math.max(duration, d);
        }

        writer.println(D/duration);
    }
}
