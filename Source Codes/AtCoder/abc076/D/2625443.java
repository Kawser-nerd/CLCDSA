import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static int[] T;
    static int[] V;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        T = sc.nextIntArray(N);
        V = sc.nextIntArray(N);
        System.out.println( solve() );
    }

    private static double solve() {
        List<Restriction> rs = mkRestriction();
        int totalTime = 0;
        for (int i = 0; i < N; i++) {
            totalTime += T[i] * 2;
        }

        // speed, time ??????????
        int currentSpeed = 0;
        double run = 0;
        for (int t = 0; t < totalTime; t++) {
            // t = 0 -> 0 to 1??????
            int nextLimit = calcMinLimit(t+1, rs);

            if( nextLimit == currentSpeed ) {
                run += currentSpeed;

            } else if( nextLimit > currentSpeed ) {
                run += currentSpeed + 0.5;
                currentSpeed++;

            } else {
                run += currentSpeed - 0.5;
                currentSpeed--;
            }
        }

        return run * 0.25;
    }

    private static int calcMinLimit(int t, List<Restriction> rs) {
        int min = Integer.MAX_VALUE;
        for (Restriction r : rs) {
            min = Math.min(r.limitAt(t), min);
        }
        return min;
    }

    private static List<Restriction> mkRestriction() {
        List<Restriction> rs = new ArrayList<>();
        rs.add(new Restriction(0, 0, 0));
        int start = 0;
        for (int i = 0; i < N; i++) {
            int end = start + T[i] * 2;
            int speed = V[i] * 2;
            rs.add( new Restriction(start, end, speed) );

            start = end;
        }
        rs.add(new Restriction(start, start, 0));
        return rs;
    }

    private static class Restriction {
        private int start;
        private int end;
        private int speed;

        public Restriction(int start, int end, int speed) {
            this.start = start;
            this.end = end;
            this.speed = speed;
        }

        public int limitAt(int t) {
            if( t < start ) {
                return speed + start - t;
            } else if( t > end ){
                return speed + t - end;
            } else {
                return speed;
            }
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