import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int tc = nextInt();

        for (int cn = 0; cn < tc; cn++) {

            int p = nextInt();
            int n = 1 << p;

            int[] most = new int[n];
            for (int i = 0; i < n; i++) {
                most[i] = nextInt();
            }

            int[][] c = new int[p][n];
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < 1 << (p - i - 1); j++) {
                    c[i][j] = nextInt();
                }
            }

            long[][][] f = new long[p + 1][p][n];
            long inf = 1000000000000L;


            for (int i = 0; i < p; i++) {
                for (int j = 0; j < 1 << (p - i - 1); j++) {

                    for (int x = 0; x <= p; x++) {


                        if (i == 0) {
                            int y = Math.min(most[2 * j], most[2 * j + 1]);
                            f[x][i][j] = x < y ? 0 : x == y ? c[i][j] : inf;
                        } else if (x < p) {
                            long a = f[x + 1][i - 1][2 * j] + f[x + 1][i - 1][2 * j + 1];
                            long b = f[x][i - 1][2 * j] + f[x][i - 1][2 * j + 1] + c[i][j];
                            f[x][i][j] = Math.min(a, b);
                        }


                    }

                }
            }



            println("Case #" + (cn + 1) + ": " + f[0][p - 1][0]);
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
