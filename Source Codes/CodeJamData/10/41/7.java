import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int tc = nextInt();

        for (int cn = 0; cn < tc; cn++) {

            int n = nextInt();

            int x = 2 * n - 1;
            int[][] d = new int[x][x];
            for (int i = 0; i < x; i++) {
                Arrays.fill(d[i], -1);
                int ii = i + 1;
                int st = i < n ? n - ii : ii - n;
                int ct = i < n ? ii : 2 * n - ii;
                for (int j = 0; j < ct; j++) {
                    d[i][st + 2 * j] = nextInt();
                }
            }

            int res = (int) 1e9;
            for (int a = 0; a < x; a++) {
                M:
                for (int b = 0; b < x; b++) {
                    int rad = 0;

                    for (int i = 0; i < x; i++) {
                        for (int j = 0; j < x; j++) {
                            if (d[i][j] == -1) {
                                continue;
                            }
                            int p = 2 * a - i, q = 2 * b - j;
                            if (d(n - 1, n - 1, p, j) < n && d[p][j] != d[i][j]) {
                                continue M;
                            }
                            if (d(n - 1, n - 1, i, q) < n && d[i][q] != d[i][j]) {
                                continue M;
                            }
                            rad = Math.max(rad, d(a, b, i, j) + 1);
                        }
                    }

                    res = Math.min(res, rad * rad - n * n);

                }
            }


            println("Case #" + (cn + 1) + ": " + res);
        }


        System.out.println((System.nanoTime() - startTime) / 1e9);
        out.close();
    }

    private static int d(int a, int b, int i, int j) {
        return Math.abs(a - i) + Math.abs(b - j);
    }

    //-----------------------------------------------------------------------------------

    private static BufferedReader in;
    private static PrintWriter out;
    private static StringTokenizer tokenizer;

    public static void main(String[] args) throws Exception {
        in = new BufferedReader(new FileReader("A-small.in"));
        out = new PrintWriter("A-small.out");
        tokenizer = new StringTokenizer("");

        new Thread(new Main()).start();
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
