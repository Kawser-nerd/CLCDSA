import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static String S;
    static int X;
    static int Y;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        S = sc.next();
        X = sc.nextInt();
        Y = sc.nextInt();
        System.out.println( solve() ? "Yes" : "No" );
    }

    static boolean solve() {
        Context context = read();

        boolean ok_x;
        {
            int sum = context.first_forward;
            for (Integer x : context.xs) {
                sum += x;
            }

            if( Math.abs(X) > sum ) return false;

            int len = sum*2 +1;
            boolean[] dp = new boolean[len];
            dp[sum + context.first_forward] = true;
            boolean[] prev = new boolean[len];
            for (Integer x : context.xs) {
                boolean[] temp = dp;
                dp = prev;
                prev = temp;

                for (int i = 0; i < len; i++) {
                    boolean b1 = false;
                    if( i-x >= 0 ) {
                        b1 = prev[i-x];
                    }
                    boolean b2 = false;
                    if( i+x < len ) {
                        b2 = prev[i+x];
                    }
                    dp[i] = b1 || b2;
                }
            }
            ok_x = dp[sum + X];
        }

        boolean ok_y;
        {
            int sum = 0;
            for (Integer y : context.ys) {
                sum += y;
            }
            if( Math.abs(Y) > sum ) return false;

            int len = sum*2 + 1;
            boolean[] dp = new boolean[len];
            dp[sum] = true;
            boolean[] prev = new boolean[len];
            for (Integer y : context.ys) {
                boolean[] temp = dp;
                dp = prev;
                prev = temp;

                for (int i = 0; i < len; i++) {
                    boolean b1 = false;
                    if( i-y >= 0 ) {
                        b1 = prev[i-y];
                    }
                    boolean b2 = false;
                    if( i+y < len ) {
                        b2 = prev[i+y];
                    }
                    dp[i] = b1 || b2;
                }
            }

            ok_y = dp[sum + Y];
        }

        return ok_x && ok_y;
    }

    static Context read() {
        int first_forward = 0;
        boolean xy = true;
        int i = 0;
        for (; i < S.length(); i++) {
            char c = S.charAt(i);
            if( c == 'F' ) {
                first_forward++;
            } else {
                xy = false;
                i++;
                break;
            }
        }

        if( i+1 == S.length() ) return new Context(first_forward, Collections.emptyList(), Collections.emptyList());

        int d = 0;
        List<Integer> xs = new ArrayList<>();
        List<Integer> ys = new ArrayList<>();

        for (; i < S.length(); i++) {
            char c = S.charAt(i);
            if( c == 'F' ) {
                d++;
            } else {
                if( xy ) {
                    xs.add(d);
                    d = 0;
                    xy = false;
                } else {
                    ys.add(d);
                    d = 0;
                    xy = true;
                }
            }
        }

        if( d > 0 ) {
            if( xy ) {
                xs.add(d);
            } else {
                ys.add(d);
            }
        }
        return new Context(first_forward, xs, ys);
    }

    static class Context {
        int first_forward;
        List<Integer> xs;
        List<Integer> ys;

        public Context(int first_forward, List<Integer> xs, List<Integer> ys) {
            this.first_forward = first_forward;
            this.xs = xs;
            this.ys = ys;
        }
    }

    static class FastScanner {

        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }

            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}