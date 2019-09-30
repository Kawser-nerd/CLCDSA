import java.io.*;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;


public class Solution {
    private static String inputFilename = "input.txt";
    private static String outputFilename = "output.txt";
    private BufferedReader in;
    private StringTokenizer line;
    private PrintWriter out;
    private boolean isDebug;

    public Solution(boolean isDebug) {
        this.isDebug = isDebug;
    }

    public void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int u = r();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = r();
        }
        if (n != k) {
            out.println("ERROR");
            return;
        }
        Arrays.sort(p);
        while (u > 0) {
            int cr = p[0];
            for (int i = 0; i < n && p[i] == cr && u > 0; i++) {
                p[i]++;
                u--;
            }
        }
        double res = 1.0;
        for (int i = 0; i < n; i++) {
            res *= p[i] / 10000.0;
        }
        out.println(String.format(Locale.ENGLISH, "%.8f", res));
    }

    private int r() throws IOException {
        double d = nextDouble();
//        if ((int) (d * 10000 + 0.01) != (int) (d * 10000)){
//            return 0;
//        }
        return (int) (d * 10000 + 0.01);
    }

    public static void main(String[] args) throws IOException {
        new Solution(Arrays.asList(args).contains("DEBUG_MODE")).run(args);
    }

    public void run(String[] args) throws IOException {
        if (isDebug) {
            in = new BufferedReader(new InputStreamReader(new FileInputStream(inputFilename)));
//            in = new BufferedReader(new InputStreamReader(System.in));
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
        }
//        out = new PrintWriter(System.out);
        out = new PrintWriter(outputFilename);

        int t = nextInt();
//        int t = 1;
        for (int i = 0; i < t; i++) {
            out.print("Case #" + (i + 1) + ": ");
            solve();
        }

        in.close();
        out.flush();
        out.close();
    }

    private int[] nextIntArray(int n) throws IOException {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    private long[] nextLongArray(int n) throws IOException {
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    private double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    private String nextToken() throws IOException {
        while (line == null || !line.hasMoreTokens()) {
            line = new StringTokenizer(in.readLine());
        }
        return line.nextToken();
    }
}
