import java.io.*;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static Pile[] P;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();

        P = new Pile[N];
        for (int i = 0; i < N; i++) {
            int size = sc.nextInt();
            P[i] = new Pile(i+1, size);
        }

        PrintWriter pw = new PrintWriter(System.out);
        for (long l : solve()) {
            pw.println(l);
        }
        pw.flush();
    }

    static long[] solve() {
        PriorityQueue<Pile> q = new PriorityQueue<>((p1, p2) -> {
            if( p1.size != p2.size ) {
                return Integer.compare(p2.size, p1.size); // size???
            } else {
                return Integer.compare(p1.no, p2.no);
            }
        });
        q.addAll( Arrays.asList(P) );

        long[] cnt = new long[N];

        Pile first = q.poll();
        int no = first.no;
        int size = first.size;
        int piles = 1;
        while( !q.isEmpty() ) {
            Pile p = q.peek();
            if( p.size == size ) {
                piles++;
                q.poll();

            } else {
                int diff = size - p.size;
                cnt[no-1] += (long)diff * piles;
                if( p.no < no ) {
                    no = p.no;
                }
                size -= diff;
                piles++;
                q.poll();
            }
        }
        cnt[no-1] += (long)size * piles;
        return cnt;
    }

    static class Pile {
        int no, size;

        public Pile(int no, int size) {
            this.no = no;
            this.size = size;
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