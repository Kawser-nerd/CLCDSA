import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicInteger;

public class BHard {
    static String[] answers;
    static AtomicInteger ready;

    static void checkRun(String s, int x, int y) {
        int xx = 0;
        int yy = 0;
        int len = 1;
        for (char ch : s.toCharArray()) {
            if (ch == 'E') {
                xx += len;
            } else if (ch == 'W') {
                xx -= len;
            } else if (ch == 'N') {
                yy += len;
            } else if (ch == 'S') {
                yy -= len;
            } else {
                throw new AssertionError();
            }
            len++;
        }
        if (xx != x || yy != y) {
            throw new AssertionError("" + xx + " != " + x + " or " + yy + " != " + y);
        }
    }

    static class Solver implements Runnable {

        int id;
        int x, y;
        String result;

        Solver(int x, int y, int id) {
            this.x = x;
            this.y = y;
            this.id = id;
        }

        @Override
        public void run() {
            int ansLen = 0;
            int ans;
            int d = Math.abs(x) + Math.abs(y);
            for (ans = 0; ansLen < d || ansLen % 2 != d % 2;) {
                ans++;
                ansLen += ans;
            }
            int oldX = x;
            int oldY = y;
            StringBuilder sb = new StringBuilder();
            for (int i = ans; i > 0; i--) {
                if (Math.abs(x) > Math.abs(y)) {
                    if (x > 0) {
                        x -= i;
                        sb.append("E");
                    } else {
                        x += i;
                        sb.append("W");
                    }
                } else {
                    if (y > 0) {
                        y -= i;
                        sb.append("N");
                    } else {
                        y += i;
                        sb.append("S");
                    }
                }
            }
            sb.reverse();
            if (x != 0 || y != 0) {
                throw new AssertionError();
            }
            checkRun(sb.toString(), oldX, oldY);
            result = sb.toString();
            answers[id] = result;
            ready.incrementAndGet();
            System.err.println(id + " ready " + result);
        }
    }



    void run() throws FileNotFoundException {
        in = new Scanner(new File("input.txt"));
        out = new PrintWriter("output_" + System.currentTimeMillis() + ".txt");
        ready = new AtomicInteger(0);
        int tests = in.nextInt();
        answers = new String[tests];
        Executor e = Executors.newFixedThreadPool(tests);
        for (int i = 0; i < tests; i++) {
            int x = in.nextInt();
            int y = in.nextInt();
            Solver s = new Solver(x, y, i);
            e.execute(s);
        }
        while (ready.get() < tests)
            ;
        for (int i = 0; i < tests; i++) {
            out.println("Case #" + (i+1) + ": " + answers[i]);
        }
        out.close();
        System.exit(0);
    }

    public static void main(String[] args) throws FileNotFoundException {
        new BHard().run();
    }

    static Scanner in;
    static PrintWriter out;
}
