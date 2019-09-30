import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int tests = nextInt();

        for (int tc = 1; tc <= tests; tc++) {

            int n = nextInt();
            int k = nextInt();
            int b = nextInt();
            int t = nextInt();
            int[] x = new int[n];
            int[] v = new int[n];
            for (int i = 0; i < n; i++) {
                x[i] = nextInt();
            }
            for (int i = 0; i < n; i++) {
                v[i] = nextInt();
            }
            int[] inds = new int[k];
            int z = 0, j = 0;
            for (int i = n; i-- > 0;) {
                if (x[i] + t * v[i] >= b) {
                    if (z < k) {
                        inds[z++] = i;
                    }
                } else {
                    j = Math.max(i, j);
                }
            }
            if (z < k) {
                println("Case #" + tc + ": IMPOSSIBLE");
                continue;
            }
            int res = 0;
            for (int i : inds) {
                if (i < j) {
                    res += j-- - i;
                }
            }
            println("Case #" + tc + ": " + res);

        }

        System.out.println((System.nanoTime() - startTime) / 1e9);
        out.close();
    }

    //-----------------------------------------------------------------------------------

    private static BufferedReader in;
    private static PrintWriter out;
    private static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("A-small.in"));
        out = new PrintWriter("A-small.out");
        tokenizer = new StringTokenizer("");

        new Thread(new A()).start();
    }

    private static String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    private static String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private static long nextLong() {
        return Long.parseLong(nextToken());
    }

    private static double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    private static BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }

    private static void println(Object o) {
        System.out.println(o);
        out.println(o);
    }

    private static void print(Object o) {
        System.out.print(o + " ");
        out.print(o + " ");
    }
}
