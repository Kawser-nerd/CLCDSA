import java.io.*;
import java.util.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    long gcd(long x, long y) {
        return x == 0 ? y : gcd(y % x, x);
    }

    long lcm(long x, long y) {
        return x / gcd(x, y) * y;
    }

    List<Integer> okShuffle(List<Integer> all) {
        Collections.sort(all);
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i * 2 < all.size(); i++) {
            res.add(all.get(i));
            res.add(all.get(all.size() - 1 - i));
        }
        return res;
    }

    void solve() {
        int n = 500;
        int need = n * 3;
        final int MAX = 2000000;
        boolean[] isPrime = new boolean[MAX];
        Arrays.fill(isPrime, true);
        List<Integer> allPrimes = new ArrayList<>();
//        List<Integer> smallPrimes = new ArrayList<>();
        for (int i = 2; i < MAX; i++) {
            if (isPrime[i]) {
                for (int j = i + i; j < MAX; j += i) {
                    isPrime[j] = false;
                }
//                if (i > 8000) {
                allPrimes.add(i);
                if (allPrimes.size() >= need) {
                    break;
                }
//                } else {
//                    if (smallPrimes.size() < 2 * n) {
//                        smallPrimes.add(i);
//                    }
//                }
            }
        }
//        System.err.println(smallPrimes.size() + " " + smallPrimes.get(smallPrimes.size() - 1));
        allPrimes = okShuffle(allPrimes);
//        smallPrimes = okShuffle(smallPrimes);
        long[][] a = new long[n][n];
        for (int i = 0; i < n; i++) {
            long val = allPrimes.get(i);
            a[i][n - i - 1] = val;
            for (int j = 1; j < n; j++) {
                int nx = i + j;
                int ny = n - i - 1 + j;
                if (nx < n && ny < n) {
                    a[nx][ny] = val * allPrimes.get(n + j - 1);
                }
            }
            for (int j = 1; j < n; j++) {
                int nx = i - j;
                int ny = n - i - 1 - j;
                if (nx >= 0 && ny >= 0) {
                    a[nx][ny] = val * allPrimes.get(2 * n + j);
                }
            }
        }
        int[] dx = new int[]{-1, 0, 0, 1};
        int[] dy = new int[]{0, -1, 1, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    long val = 1;
                    for (int it = 0; it < dx.length; it++) {
                        int ni = i + dx[it], nj = j + dy[it];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            val = lcm(val, a[ni][nj]);
                        }
                    }
                    a[i][j] = val + 1;
                }
            }
        }
        long max = 0;
        HashSet<Long> all = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                all.add(a[i][j]);
                max = Math.max(max, a[i][j]);
                if (a[i][j] > 1e15) {
//                    throw new AssertionError(a[i][j]);
                }
                for (int it = 0; it < 4; it++) {
                    int ni = i + dx[it], nj = j + dy[it];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        long f = Math.max(a[i][j], a[ni][nj]) % Math.min(a[i][j], a[ni][nj]);
                        if (f != 1) {
                            throw new AssertionError();
                        }
                    }
                }
            }
        }

//        System.err.println("max = " + max / 1e15);
//        System.err.println(all.size());

        int askedN = in.nextInt();
        for (int i = 0; i < askedN; i++) {
            for (int j = 0; j < askedN; j++) {
                out.print(a[i][j] + " ");
            }
            out.println();
        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                System.err.print(a[i][j] + " ");
//            }
//            System.err.println();
//        }
//        Random rnd = new Random(123);
//        long val = 1;
//        for (int i = 0; i < 3; i++) {
//            long mul = allPrimes.get(rnd.nextInt(allPrimes.size()));
//            val *= mul;
//        }
//        System.err.println(val);
//        System.err.println(allPrimes.size() + " " + need);
    }

    void solve123() {
        int n = 10;
        long[][] a = new long[n][n];
        Random rnd = new Random(13);
        final int m = 2 + rnd.nextInt(100);
        a[0][0] = m + 2 + rnd.nextInt(10);
        HashSet<Long> was = new HashSet<>();
        was.add(a[0][0]);
        was.add(1L);
        for (int i = 1; i < n; i++) {
            a[0][i] = a[0][i - 1] * (i < 10 ? 2 : 1) + m;
            was.add(a[0][i]);
        }
        for (int i = 1; i < n; i++) {
            a[i][0] = a[i - 1][0] * (i < 10 ? 3 : 1) + m;
            was.add(a[i][0]);
        }
        final long MAX = (long) 1e7;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                long x = a[i - 1][j], y = a[i][j - 1];
                long g = gcd(x - m, y - m);
                if (g > m && !was.contains(g)) {
                    a[i][j] = g;
                } else {
                    a[i][j] = lcm(x, y) + m;
                }
                was.add(a[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.err.print(a[i][j] + " ");
            }
            System.err.println();
        }
    }


    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}