import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class Main {

    private void solve() throws IOException {
        int x = nextInt();
        int y = nextInt();
        int z = nextInt();
        int n = x + y + z;
        Coin[] a = new Coin[n];
        long res = 0;
        for (int i = 0; i < n; i++) {
            long aa = nextInt();
            long bb = nextInt();
            long cc = nextInt();
            res += cc;
            a[i] = new Coin(aa - cc, bb - cc);
        }
        Arrays.sort(a, new Comparator<Coin>() {
            @Override
            public int compare(Coin o1, Coin o2) {
                return Long.compare(o1.b - o1.a, o2.b - o2.a);
            }
        });
//        for (int i = 0; i < n; i++) {
//            out.println(a[i].a + " " + a[i].b);
//        }
        long[] left = new long[n + 1];
        PriorityQueue<Coin> pq = new PriorityQueue<Coin>(new Comparator<Coin>() {
            @Override
            public int compare(Coin o1, Coin o2) {
                return Long.compare(o1.a, o2.a);
            }
        });
        long s = 0;
        for (int i = 0; i < n; i++) {
            pq.add(a[i]);
            s += a[i].a;
            if (pq.size() > x) {
                s -= pq.remove().a;
            }
            left[i + 1] = s;
        }

        long[] right = new long[n + 1];
        pq = new PriorityQueue<Coin>(new Comparator<Coin>() {
            @Override
            public int compare(Coin o1, Coin o2) {
                return Long.compare(o1.b, o2.b);
            }
        });
        s = 0;
        for (int i = 0; i < n; i++) {
            pq.add(a[n - 1 - i]);
            s += a[n - 1 - i].b;
            if (pq.size() > y) {
                s -= pq.remove().b;
            }
            right[i + 1] = s;
        }

        long max = Long.MIN_VALUE;

        for (int i = 0; i <= n; i++) {
            if (i >= x && (n - i) >= y) {
                max = Math.max(max, left[i] + right[n - i]);
//                System.out.println("> " + i + " " + (left[i] + right[n - i]));
            }
        }


//        System.out.println(Arrays.toString(left));
//        System.out.println(Arrays.toString(right));
//        System.out.println(res + " " + max);

        out.println(res + max);
    }

    class Coin {
        long a, b;

        public Coin(long a, long b) {
            this.a = a;
            this.b = b;
        }
    }

    // ------------------

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}