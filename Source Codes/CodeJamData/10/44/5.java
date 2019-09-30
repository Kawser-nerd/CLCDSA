import java.io.*;
import java.util.*;
import java.math.*;

public class Main implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int tc = nextInt();

        for (int cn = 0; cn < tc; cn++) {

            int n = nextInt();
            int m = nextInt();

            int x1 = nextInt();
            int y1 = nextInt();
            int x2 = nextInt();
            int y2 = nextInt();

            int[] x = new int[m];
            int[] y = new int[m];

            for (int i = 0; i < m; i++) {
                x[i] = nextInt();
                y[i] = nextInt();
            }

            print("Case #" + (cn + 1) + ":");

            for (int i = 0; i < m; i++) {
                double d = Math.hypot(x1 - x2, y1 - y2);
                double a = Math.hypot(x1 - x[i], y1 - y[i]);
                double b = Math.hypot(x2 - x[i], y2 - y[i]);

                if (Math.abs(d - a - b) < 1e-9) {
                    print("0");
                    continue;
                }

                double p = (d + a + b) / 2;
                double xord = 4 * Math.sqrt(p * (p - a) * (p - b) * (p - d)) / d;

                double a1 = Math.acos(  Math.min(Math.max(-1, (d * d + a * a - b * b) / 2 / d / a), 1)  );
                double a2 = Math.acos(  Math.min(Math.max(-1, (d * d + b * b - a * a) / 2 / d / b), 1)  );

                print(area(a, a1) + area(b, a2));
            }
            println("");
        }


        System.out.println((System.nanoTime() - startTime) / 1e9);
        out.close();
    }

    private static double area(double r, double a) {
        a *= 2;
        return r * r * a / 2 - r * r * Math.sin(a) / 2;
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
