import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    private NotMyScanner in;
    private PrintWriter out;
    private Timer timer = new Timer();

    // Или пиши красиво, или не пиши вообще.

    class Tuple3 {
        int a, b, c;

        public Tuple3(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public String toString() {
            return (a + 1) + " " + (b + 1) + " " + (c + 1);
        }
    }

    private void solve() throws IOException {
        int j = in.nextInt(), p = in.nextInt(), s = in.nextInt(), k = in.nextInt();

        if (j == 3 && k == 1) {
            out.println(9);
            out.println("1 1 2\n" +
                    "1 2 1\n" +
                    "1 3 3\n" +
                    "2 1 1\n" +
                    "2 2 3\n" +
                    "2 3 2\n" +
                    "3 1 3\n" +
                    "3 2 2\n" +
                    "3 3 1");
            return;
        }

        if (j == 3 && k == 2) {
            out.println(18);
            out.println("1 1 1\n" +
                    "1 1 3\n" +
                    "1 2 1\n" +
                    "1 2 2\n" +
                    "1 3 2\n" +
                    "1 3 3\n" +
                    "2 1 1\n" +
                    "2 1 2\n" +
                    "2 2 2\n" +
                    "2 2 3\n" +
                    "2 3 1\n" +
                    "2 3 3\n" +
                    "3 1 2\n" +
                    "3 1 3\n" +
                    "3 2 1\n" +
                    "3 2 3\n" +
                    "3 3 1\n" +
                    "3 3 2");
            return;
        }

        if (j == 3) {
            out.println(27);
            for (int i = 0; i < j; i++) {
                for (int l = 0; l < p; l++) {
                    for (int m = 0; m < s; m++) {
                        out.println(new Tuple3(i, l, m));
                    }
                }
            }
            return;
        }

        ArrayList<Tuple3> sets = new ArrayList<Tuple3>(j * p * s);

        for (int i = 0; i < j; i++) {
            for (int l = 0; l < p; l++) {
                for (int m = 0; m < s; m++) {
                    sets.add(new Tuple3(i, l, m));
                }
            }
        }

        int best = 0, mask = 0;
        loop:
        for (int m = 0; m < (1 << sets.size()); m++) {
            int[][] cntA = new int[j][p], cntB = new int[j][s], cntC = new int[p][s];
            int curCnt = 0;
            for (int i = 0; i < sets.size(); i++) {
                if (((m >> i) & 1) != 0) {
                    curCnt++;
                    Tuple3 cur = sets.get(i);

                    cntA[cur.a][cur.b]++;
                    cntB[cur.a][cur.c]++;
                    cntC[cur.b][cur.c]++;

                    if (cntA[cur.a][cur.b] > k || cntB[cur.a][cur.c] > k || cntC[cur.b][cur.c] > k) {
                        continue loop;
                    }
                }
            }
            if (curCnt > best) {
                best = curCnt;
                mask = m;
            }
        }

        out.println(best);
        for (int i = 0; i < sets.size(); i++) {
            if (((mask >> i) & 1) != 0) {
                out.println(sets.get(i));
            }
        }
    }

    private void run() throws IOException {
        in = new NotMyScanner("C-small-attempt0.in");
        out = new PrintWriter(new FileOutputStream("result.txt"), false);
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ": ");
            timer.start();
            solve();
            timer.stop();
        }
        out.close();
    }

    public static void main(String[] args) throws IOException {
        new Main().run();
    }
}

class NotMyScanner {

    private final BufferedReader br;
    private StringTokenizer st;
    private String last;

    public NotMyScanner() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public NotMyScanner(String path) throws IOException {
        br = new BufferedReader(new FileReader(path));
    }

    public NotMyScanner(String path, String decoder) throws IOException {
        br = new BufferedReader(new InputStreamReader(new FileInputStream(path), decoder));
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreElements())
            st = new StringTokenizer(br.readLine());
        last = null;
        return st.nextToken();
    }

    String nextLine() throws IOException {
        st = null;
        return (last == null) ? br.readLine() : last;
    }

    boolean hasNext() {
        if (st != null && st.hasMoreElements())
            return true;

        try {
            while (st == null || !st.hasMoreElements()) {
                last = br.readLine();
                st = new StringTokenizer(last);
            }
        } catch (Exception e) {
            return false;
        }

        return true;
    }

    String[] nextStrings(int n) throws IOException {
        String[] arr = new String[n];
        for (int i = 0; i < n; i++)
            arr[i] = next();
        return arr;
    }

    String[] nextLines(int n) throws IOException {
        String[] arr = new String[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextLine();
        return arr;
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    int[] nextInts(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    Integer[] nextIntegers(int n) throws IOException {
        Integer[] arr = new Integer[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextInt();
        return arr;
    }

    int[][] next2Ints(int n, int m) throws IOException {
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = nextInt();
        return arr;
    }

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    long[] nextLongs(int n) throws IOException {
        long[] arr = new long[n];
        for (int i = 0; i < n; i++)
            arr[i] = nextLong();
        return arr;
    }

    long[][] next2Longs(int n, int m) throws IOException {
        long[][] arr = new long[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = nextLong();
        return arr;
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(next().replace(',', '.'));
    }

    double[] nextDoubles(int size) throws IOException {
        double[] arr = new double[size];
        for (int i = 0; i < size; i++)
            arr[i] = nextDouble();
        return arr;
    }

    boolean nextBool() throws IOException {
        String s = next();
        if (s.equalsIgnoreCase("true") || s.equals("1"))
            return true;

        if (s.equalsIgnoreCase("false") || s.equals("0"))
            return false;

        throw new IOException("Boolean expected, String found!");
    }
}