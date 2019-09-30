import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static double V, X;
    static double[] R, C;

    static double cal() {
        if (C[0] == C[1]) {
            return V / (R[0] + R[1]);
        }

        X *= V;
        for (int i = 0; i < N; ++i) {
            C[i] *= R[i];
        }

        double b = (X * R[0] / C[0] - V) / (C[1] * R[0] / C[0] - R[1]);
        double a = (V - b * R[1]) / R[0];
        return Math.max(a, b);
    }

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            N = scan.nextInt();
            V = scan.nextDouble();
            X = scan.nextDouble();
            R = new double[N];
            C = new double[N];
            for (int i = 0; i < N; ++i) {
                R[i] = scan.nextDouble();
                C[i] = scan.nextDouble();
            }
            double res = 0;
            if (N == 1) {
                if (C[0] == X) {
                    res = V / R[0];
                } else {
                    System.out.println(String.format("Case #%d: IMPOSSIBLE", taskIndex));
                    continue;
                }
            } else {
                if ((C[0] > X && C[1] > X) || (C[0] < X && C[1] < X)) {
                    System.out.println(String.format("Case #%d: IMPOSSIBLE", taskIndex));
                    continue;
                } else {
                    res = cal();
                }
            }

            System.out.println(String.format("Case #%d: %.8f", taskIndex, res));
        }
    }
}

class FastScanner {
    BufferedReader in;
    StringTokenizer tok;

    public FastScanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (Exception e) {
            throw new InputMismatchException();
        }
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }
        return tok.nextToken();
    }

    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

    public long nextLong() {
        return Long.parseLong(nextToken());
    }

}
