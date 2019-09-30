import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int N;
    static Box[] B;

    public static void main(String[] args) {
        FastScanner fc = new FastScanner(System.in);
        N = fc.nextInt();
        B = new Box[N];
        for (int i = 0; i < N; i++) {
            int x = fc.nextInt();
            int y = fc.nextInt();
            B[i] = new Box(i, x, y);
            B[i].reset();
        }
        System.out.println(solve());
    }

    static long solve() {
        if( N == 1 ) {
            return (long)(B[0].y - B[0].x) * (B[0].y - B[0].x);
        };

        // x < y??????????????????
        int min = Integer.MAX_VALUE;
        int max = -1;

        for (int i = 0; i < N; i++) {
            if( min > B[i].x ) {
                min = B[i].x;
            }
            if( max < B[i].y ) {
                max = B[i].y;
            }
        }

        return Math.min(caseMinMaxIsOtherSize(min, max), caseMinMaxIsSameSide(min, max));
    }

    static long caseMinMaxIsSameSide(int min, int max) {
        // min, max ?????????????
        // ????(?????????????????????????????

        Arrays.sort(B, Comparator.comparing(b -> b.x));

        // TreeSet, Set?????????????
        TreeSet<Box> xs = new TreeSet<>((b1, b2) -> {
            if( b1.x != b2.x ) return Integer.compare(b1.x, b2.x);
            else return Integer.compare(b1.i, b2.i);
        });
        TreeSet<Box> ys = new TreeSet<>((b1, b2) -> {
            if( b1.y != b2.y ) return Integer.compare(b1.y, b2.y);
            else return Integer.compare(b1.i, b2.i);
        });
        xs.addAll(Arrays.asList(B));
        if( xs.size() != N ) throw new IllegalArgumentException();

        long ans = (long)(xs.last().x - xs.first().x) * (max - min);
        if( ans < 0 ) throw new IllegalArgumentException("wtf0 " + xs.last().x + " " + xs.first().x);
        for (int i = 0; i < N-1; i++) {
            Box box = xs.pollFirst();
            ys.add(box);

            int xmax = xs.last().x;
            int xmin = xs.first().x;
            int ymax = ys.last().y;
            int ymin = ys.first().y;

            ans = Math.min((long)(Math.max(xmax, ymax) - Math.min(xmin, ymin)) * (max - min), ans);
        }
        Box box = xs.pollFirst();
        ys.add(box);
        if( ys.size() != N ) throw new IllegalArgumentException();
        int ymax = ys.last().y;
        int ymin = ys.first().y;
        ans = Math.min((long)(ymax - ymin) * (max - min), ans);

        return ans;
    }

    static long caseMinMaxIsOtherSize(int min, int max) {
        int rmin = min;
        int rmax = -1;
        int bmin = Integer.MAX_VALUE;
        int bmax = max;

        for (Box b : B) {
            // box???? x < y ????????????
            b.reset();

            rmax = Math.max(b.x, rmax);
            bmin = Math.min(b.y, bmin);
        }

        // System.out.println("(" + rmax + " - " + rmin + ") * (" + bmax + " - " +  bmin + ")");
        return (long)(rmax - rmin) * (bmax - bmin);
    }

    static class Box {
        int i, x, y;

        public Box(int i, int x, int y) {
            this.i = i;
            this.x = x;
            this.y = y;
        }

        void flip() {
            int t = x;
            x = y;
            y = t;
        }

        void reset() {
            if( x > y ) flip();
        }
    }

    @SuppressWarnings("unused")
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