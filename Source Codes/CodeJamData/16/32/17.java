import java.io.*;
import java.util.StringTokenizer;

public class Main {

    private NotMyScanner in;
    private PrintWriter out;
//    private Timer timer = new Timer();

    // Или пиши красиво, или не пиши вообще.

    private void solve() throws IOException {
        int b = in.nextInt();
        long m = in.nextLong();

        if (1L << (b - 2) < m) {
            out.println("IMPOSSIBLE");
            return;
        }

        out.println("POSSIBLE");

        boolean[][] g = new boolean[b][b];
        g[0][b - 1] = true;
        m--;

        for (int i = 1; i < b; i++) {
            for (int j = i + 1; j < b; j++) {
                g[i][j] = true;
            }
        }

        for (int p = b - 3; p >= 0; p--) {
            if (((m >> p) & 1) != 0) {
                g[0][b - 2 - p] = true;
            }
        }

        for (int i = 0; i < b; i++) {
            for (int j = 0; j < b; j++) {
                out.print(g[i][j] ? '1' : '0');
            }
            out.println();
        }
    }

    private void run() throws IOException {
        in = new NotMyScanner("B-large.in");
        out = new PrintWriter(new FileOutputStream("result.txt"), false);
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            out.print("Case #" + i + ": ");
            solve();
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