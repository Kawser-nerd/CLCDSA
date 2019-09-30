/**
 * @author cplayer on 2018/6/23.
 * @version 1.0
 */

import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        try {
            InputReader in;
            PrintWriter out;
            boolean useOutput = false;
            // if (System.getProperty("ONLINE_JUDGE") == null) useOutput = true;
            if (useOutput) {
                FileInputStream fin = new FileInputStream(new File("src/data.in"));
                in = new InputReader(fin);
                FileOutputStream fout = new FileOutputStream(new File("src/data.out"));
                out = new PrintWriter(fout);
            } else {
                InputStream inputStream = System.in;
                in = new InputReader(inputStream);
                OutputStream outputStream = System.out;
                out = new PrintWriter(outputStream);
            }
            Solver solver = new Solver();
            solver.solve(in, out);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class Solver {

        public void solve (InputReader cin, PrintWriter cout) {
            try {
                int n = cin.nextInt();
                long x = cin.nextLong();
                long[] dis = new long[n + 1];
                for (int i = 1; i <= n; ++i) {
                    dis[i] = cin.nextLong();
                }
                // prefix
                for (int i = 2; i <= n; ++i) {
                    dis[i] += dis[i - 1];
                }
                long result = Long.MAX_VALUE;
                for (int k = 1; k <= (n / 2 + 1); ++k) {
                    long tmp = 0;
                    for (int i = 1; i <= (n / k) + 1; ++i) {
                        long para = 0;
                        if (i == 1) {
                            para = 5;
                        } else {
                            para = (2 * i + 1);
                        }
                        int upper = n - (i - 1) * k;
                        int lower = n - i * k;
                        if (lower < 0) {
                            lower = 0;
                            tmp += (dis[upper] - dis[lower]) * para;
                            break;
                        } else {
                            tmp += (dis[upper] - dis[lower]) * para;
                        }
                        if (tmp < 0) {
                            tmp = Long.MAX_VALUE - k * x;
                            break;
                        }
                    }
                    tmp += k * x;
                    result = Math.min(result, tmp);
                }
                cout.println(result + n * x);
            } catch (RuntimeException e) {
                e.printStackTrace();
                return;
            } catch (Exception e) {
                e.printStackTrace();
                return;
            }

        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 1000000);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }

}