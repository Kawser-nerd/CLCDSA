import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
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
        A[] a = new A[n];
        for (int i = 0; i < n; i++) {
            a[i] = new A();
            a[i].r = nextInt();
            a[i].h = nextInt();
        }
        double res = 0;
        for (int i = 0; i < n; i++) {
            A[] b = Arrays.copyOf(a, n);
            {
                A tmp = b[i];
                b[i] = b[n - 1];
                b[n - 1] = tmp;
            }
            Arrays.sort(b, 0, n - 1, new Comparator<A>() {
                @Override
                public int compare(A o1, A o2) {
                    return -Long.compare(o1.h * (long) o1.r, o2.h * (long) o2.r);
                }
            });
            double tmp = b[n - 1].r * (long) b[n - 1].r + 2 * b[n - 1].h * (long) b[n - 1].r;
            int c = k - 1;
            for (int j = 0; j < n - 1 && c > 0; j++) {
                if (b[j].r <= b[n - 1].r) {
                    tmp += 2 * b[j].h * (long) b[j].r;
                    c--;
                }
            }
            tmp *= Math.PI;
            res = Math.max(res, tmp);
        }
        out.println(String.format(Locale.ENGLISH, "%.8f", res));
    }

    private static class A {
        int r;
        int h;
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
