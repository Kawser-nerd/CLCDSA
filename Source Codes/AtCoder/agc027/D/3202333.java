import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        DModuloMatrix solver = new DModuloMatrix();
        solver.solve(1, in, out);
        out.close();
    }

    static class DModuloMatrix {
        int[] dx = new int[]{-1, 0, 1, 0};
        int[] dy = new int[]{0, -1, 0, 1};

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int n = 500;
            List<Integer> primes = NumberTheory.primes(20000);
            primes = primes.subList(0, 1498);
            primes = shuffle(primes);
            long[][] a = new long[n][n];
            Set<Long> all = new HashSet<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 2 == 0) {
                        a[i][j] = primes.get(i + j) * primes.get(999 + i - j);
                        all.add(a[i][j]);
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i + j) % 2 == 1) {
                        long lcm = 1;
                        for (int d = 0; d < 4; d++) {
                            int ni = i + dx[d], nj = j + dy[d];
                            if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                                lcm = NumberTheory.lcm(lcm, a[ni][nj]);
                            }
                        }
                        long cur = lcm + 1;
                        while (all.contains(cur)) {
                            cur += lcm;
                        }
                        a[i][j] = cur;
                        all.add(a[i][j]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d], nj = j + dy[d];
                        if (0 <= ni && ni < n && 0 <= nj && nj < n) {
                            if (Math.max(a[ni][nj], a[i][j]) % Math.min(a[i][j], a[ni][nj]) != 1) {
                                System.err.println(a[i][j] + " " + a[ni][nj]);
                                throw new AssertionError();
                            }
                        }
                    }
                }
            }
//        System.err.println(all.size());
//        System.err.println(Collections.max(all));
//        System.err.println(Long.toString(Collections.max(all)).length());

            n = in.nextInt();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    out.print(a[i][j] + " ");
                }
                out.println();
            }
        }

        private List<Integer> shuffle(List<Integer> primes) {
            List<Integer> small = new ArrayList<>(primes.subList(0, primes.size() / 2));
            List<Integer> large = new ArrayList<>(primes.subList(primes.size() / 2, primes.size()));
            Collections.reverse(large);
            List<Integer> result = new ArrayList<>();
            for (int i = 0; i < primes.size() / 2; i++) {
                result.add(small.get(i));
                result.add(large.get(i));
            }
            return result;
        }

    }

    static class NumberTheory {
        public static long gcd(long a, long b) {
            if (a == 0) {
                return b;
            }
            return gcd(b % a, a);
        }

        public static long lcm(long a, long b) {
            return a / gcd(a, b) * b;
        }

        public static List<Integer> primes(int max) {
            boolean[] isPrime = new boolean[max + 1];
            Arrays.fill(isPrime, true);
            List<Integer> ans = new ArrayList<>();
            for (int i = 2; i <= max; i++) {
                if (isPrime[i]) {
                    ans.add(i);
                    for (int j = 2 * i; j <= max; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
            return ans;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}