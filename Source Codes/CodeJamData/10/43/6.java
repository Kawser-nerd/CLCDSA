import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int tc = nextInt();

        for (int cn = 0; cn < tc; cn++) {

            boolean[][] b = new boolean[111][111];

            int p = nextInt();

            for (int rect = 0; rect < p; rect++) {
                int x1 = nextInt();
                int y1 = nextInt();
                int x2 = nextInt() + 1;
                int y2 = nextInt() + 1;
                for (int i = x1; i < x2; i++) {
                    for (int j = y1; j < y2; j++) {
                        b[i][j] = true;
                    }
                }
            }

            int res = 0;

            boolean[][] bb = new boolean[111][111];
            M:
            while (true) {
                for (int i = 0; i < b.length; i++) {
                    for (int j = 0; j < b.length; j++) {
                        if (b[i][j]) {


                            for (int t = 0; t < b.length; t++) {
                                System.arraycopy(b[t], 0, bb[t], 0, b.length);
                            }
                            for (int x = 1; x < b.length - 1; x++) {
                                for (int y = 1; y < b.length - 1; y++) {
                                    if (b[x - 1][y] && b[x][y - 1]) {
                                        bb[x][y] = true;
                                    }
                                    if (!b[x - 1][y] && !b[x][y - 1]) {
                                        bb[x][y] = false;
                                    }
                                }
                            }
                            for (int t = 0; t < b.length; t++) {
                                System.arraycopy(bb[t], 0, b[t], 0, b.length);
                            }

                            res++;
                            continue M;
                        }
                    }
                }
                break;
            }

            println("Case #" + (cn + 1) + ": " + res);
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
