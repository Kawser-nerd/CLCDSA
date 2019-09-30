import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
    public static final char TASK = 'b';
//    public static final boolean IS_SOUT = true;
    public static final boolean IS_SOUT = false;
    public static final String FILE_MASK = "%-small-attempt0";
//    public static final String FILE_MASK = "%-large";

    public static String solve(int x, int y) {
        for (int k = 1; k <= 2000; k++) {
            String curSol = solve(x, y, k);
            if (curSol != null) {
                return curSol;
            }
        }
        throw new RuntimeException("=( for " + x + " " + y);
    }

    private static int price(int x, int y) {
        return Math.abs(x) + Math.abs(y);
    }

    private static String solve(int x, int y, int k) {
        char[] steps = new char[k];
        for (int cur = k; cur >= 1; cur--) {
            char curStep = '0';
            int curPrice = Integer.MAX_VALUE;

            // north
            if (curPrice > price(x, y + cur)) {
                curPrice = price(x, y + cur);
                curStep = 'N';
            }
            // south
            if (curPrice > price(x, y - cur)) {
                curPrice = price(x, y - cur);
                curStep = 'S';
            }
            // west
            if (cur > price(x - cur, y)) {
                curPrice = price(x - cur, y);
                curStep = 'W';
            }
            // east
            if (cur > price(x + cur, y)) {
                curPrice = price(x + cur, y);
                curStep = 'E';
            }

            steps[cur - 1] = curStep;
            if (curStep == 'N') {
                y += cur;
            }
            if (curStep == 'S') {
                y -= cur;
            }
            if (curStep == 'W') {
                x -= cur;
            }
            if (curStep == 'E') {
                x += cur;
            }
        }

        if (price(x, y) == 0) {
            return new String(steps);
        } else {
            return null;
        }
    }

    public void runOnce(Scanner input, PrintWriter output) {
        int x = -input.nextInt();
        int y = -input.nextInt();

        output.println(solve(x, y));
    }

    public void run(Scanner input, PrintWriter output) {
        int t = input.nextInt();

        input.nextLine();
        for (int tt = 1; tt <= t; tt++) {
            output.print("Case #" + tt + ": ");
            runOnce(input, output);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner input;
        PrintWriter output;

        if (IS_SOUT) {
            input = new Scanner(System.in);
            output = new PrintWriter(System.out);
        } else {
            input = new Scanner(new File(FILE_MASK.replace('%', TASK) + ".in"));
            output = new PrintWriter(new File(FILE_MASK.replace('%', TASK) + ".out"));
        }

        new B().run(input, output);

        input.close();
        output.close();
    }
}
