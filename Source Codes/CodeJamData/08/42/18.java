import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class B {

    private String solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        int a = nextInt();

        for (int x1 = 1; x1 <= n; x1++) {
            for (int y2 = a / x1; y2 <= m; y2++) {
                int x2y1 = x1 * y2 - a;
                if (x2y1 == 0) {
                    return getA(x1, y2, 0, 0);
                } else if (x2y1 > 0) {
                    int x2 = x2y1;
                    int y1 = 1;

                    int p = 0;
                    while (true) {
                        if (y1 > m || p >= primes.length) {
                            break;
                        }
                        if (x2 <= n && y1 <= m) {
                            return getA(x1, y2, x2, y1);
                        }
                        if (x2 % primes[p] == 0) {
                            x2 /= primes[p];
                            y1 *= primes[p];
                        } else {
                            p++;
                        }
                    }
                }
            }
        }
        return "IMPOSSIBLE";
    }

    private static String getA(int x1, int y2, int x2, int y1) {
        return "0 0 " + x1 + " " + y1 + " " + x2 + " " + y2;
    }

    int[] primes = getPrimes(1500);

//    private static final int MAXN = 100000100;
//
//    boolean[] factorizeToSmall = new boolean[MAXN];
//
//    private void prepare() {
//        int[] primes = getPrimes(1500);
//
//        factorizeToSmall[0] = true;
//        factorizeToSmall[1] = true;
//
//        for (int i = 2; i < factorizeToSmall.length; i++) {
//
//            if (i % 1000000 == 0) {
//                System.out.println(i);
//                System.out.flush();
//            }
//
//            int x = i;
//            for (int p = 1; p < primes.length && primes[p] * primes[p] <= x; p++) {
//                while (x % primes[p] == 0) {
//                    x /= primes[p];
//                }
//            }
//            factorizeToSmall[i] = x == 1;
//        }
//    }

    private static int[] getPrimes(int count) {
        int[] x = new int[count];
        x[0] = 2;
        int z = 1;
        for (int i = 1; i < x.length; i++) {
            do {
                z += 2;
            } while (!isPrime(z, x));
            x[i] = z;
        }

        return x;
    }

    private static boolean isPrime(int z, int[] x) {
        int i = 0;
        while (x[i] * x[i] <= z) {
            if (z % x[i] == 0) {
                return false;
            }
            i++;
        }
        return true;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter writer = new PrintWriter(new File("B-large.out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new B().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}