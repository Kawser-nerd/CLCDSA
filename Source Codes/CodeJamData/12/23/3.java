
import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class C implements Runnable {

    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok = new StringTokenizer("");

    public static void main(String[] args) {
        new Thread(null, new C(), "", 256 * (1L << 20)).start();
    }

    public void run() {
        try {
            long t1 = System.currentTimeMillis();
            in = new BufferedReader(new FileReader("src/input.txt"));
            out = new PrintWriter(new FileWriter("src/output.txt"));
            Locale.setDefault(Locale.US);
            solve();
            in.close();
            out.close();
            long t2 = System.currentTimeMillis();
            System.err.println("Time = " + (t2 - t1));
        } catch (Throwable t) {
            t.printStackTrace(System.err);
            System.exit(-1);
        }
    }

    String nextString() throws IOException {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextString());
    }
    HashSet<Long> exist;
    boolean exitFlag;
    long rememberSum;

    void solve() throws IOException {
        long ct = nextLong();
        for (long t = 1; t <= ct; t++) {
            exitFlag = false;
            exist = new HashSet<Long>();
            out.println("Case #" + t + ":");
            int n = (int)nextLong();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            boolean[] used = new boolean[n];
            for (long i = 1; i <= n; i++) {
                generate(0, used, a, 0, i);
            }
            exitFlag = false;
            Arrays.fill(used, false);
            for (long i = 1; i <= n; i++) {
                generateAgain(0, used, a,0, i);
            }
        }
    }

    void printResult(boolean[] used, long[] a) {
        for (int i = 0; i < used.length; i++) {
            if (used[i]) {
                out.print(a[i] + " ");
            }
        }
        out.println();
    }

    void generate(int x, boolean[] used, long[] a, long sum, long len) {
        if (exitFlag) {
            return;
        }

        if (x == used.length) {
            if (len == 0) {
                if (exist.contains(sum)) {
                    //  out.println(sum);
                    printResult(used, a);
                    exitFlag = true;
                    rememberSum = sum;
                }
                exist.add(sum);
            }
            return;
        }

        generate(x + 1, used, a, sum, len);
        used[x] = true;
        if (len > 0) {
            generate(x + 1, used, a, sum + a[x], len - 1);
        }
        used[x] = false;
    }

    void generateAgain(int x, boolean[] used, long[] a, long sum, long len) {
        if (exitFlag) {
            return;
        }

        if (x == used.length) {
            // out.println("get sum " + sum);
            if (sum == rememberSum) {
                printResult(used, a);
                exitFlag = true;
            }
            return;
        }

        generateAgain(x + 1, used, a, sum, len);
        used[x] = true;
        if (len > 0) {
            generateAgain(x + 1, used, a, sum + a[x], len - 1);
        }
        used[x] = false;
    }
}
