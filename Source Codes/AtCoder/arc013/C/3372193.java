import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static Touhu[] T;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();
        T = new Touhu[N];
        for (int i = 0; i < N; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            int z = sc.nextInt();
            int m = sc.nextInt();
            Hapa[] hs = new Hapa[m];
            for (int j = 0; j < m; j++) {
                hs[j] = new Hapa(sc.nextInt(), sc.nextInt(), sc.nextInt());
            }
            T[i] = new Touhu(x, y, z, hs);
        }
        System.out.println(solve() ? "WIN" : "LOSE");
    }

    static boolean solve() {
        // (x, y, z) * 2
        int[] piles = new int[N*6];

        for (int i = 0; i < N; i++) {
            int minx = Integer.MAX_VALUE;
            int maxx = -1;
            int miny = Integer.MAX_VALUE;
            int maxy = -1;
            int minz = Integer.MAX_VALUE;
            int maxz = -1;

            for (Hapa h : T[i].hs) {
                minx = Math.min(h.x, minx);
                maxx = Math.max(h.x, maxx);
                miny = Math.min(h.y, miny);
                maxy = Math.max(h.y, maxy);
                minz = Math.min(h.z, minz);
                maxz = Math.max(h.z, maxz);
            }

            piles[i*6 + 0] = minx;
            piles[i*6 + 1] = T[i].x - maxx - 1;
            piles[i*6 + 2] = miny;
            piles[i*6 + 3] = T[i].y - maxy - 1;
            piles[i*6 + 4] = minz;
            piles[i*6 + 5] = T[i].z - maxz - 1;
        }

        // System.out.println(Arrays.toString(piles));

        // ??????????????????
        // ????????????????????????
       return calcNim(piles);
    }

   static boolean calcNim(int[] piles) {
       int xor = 0;
       for (int pile : piles) {
           xor ^= pile;
       }
       return xor != 0;
    }


    static class Touhu {
        int x, y, z;
        Hapa[] hs;

        public Touhu(int x, int y, int z, Hapa[] hs) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.hs = hs;
        }
    }

    static class Hapa {
        int x, y, z;

        public Hapa(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
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