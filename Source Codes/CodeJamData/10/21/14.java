import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {
    public void run() {
        long startTime = System.nanoTime();

        int tests = nextInt();

        class E {
            List<E> x = new ArrayList<E>();

            String name;

            public E(String name) {
                this.name = name;
            }

            int add(String[] s, int i) {
                if (i == s.length) {
                    return 0;
                }
                for (E e : x) {
                    if (e.name.equals(s[i])) {
                        return e.add(s, i + 1);
                    }
                }
                E e = new E(s[i]);
                x.add(e);
                return e.add(s, i + 1) + 1;
            }
        }

        for (int tc = 1; tc <= tests; tc++) {

            E root = new E("");

            int n = nextInt();
            int m = nextInt();
            int res = 0;

            for (int i = 0; i < n; i++) {
                root.add(nextToken().substring(1).split("/"), 0);
            }
            for (int i = 0; i < m; i++) {
                res += root.add(nextToken().substring(1).split("/"), 0);
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
