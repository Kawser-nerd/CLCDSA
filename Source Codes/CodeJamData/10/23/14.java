import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int max = 501, M = 100003;

        int[][] C = new int[max][max];
        for (int i = 1; i < max; i++) {
            C[0][0] = C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
            }
        }

        long[][] f = new long[max][max];
        for (int n = 2; n < f.length; n++) {
            f[n][1] = 1;
            for (int k = 2; k < n; k++) {

                for (int i = 1; i < k; i++) {
                    f[n][k] += f[k][i] * C[n - k - 1][k - i - 1];
                    f[n][k] %= M;
                }

            }
        }

        int tests = nextInt();
        for (int tc = 1; tc <= tests; tc++) {
            int n = nextInt();
            long res = 0;
            for (int i = 1; i < n; i++) {
                res = (res + f[n][i]) % M;
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
