import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

/**
 * @author Ivan Romanov
 */
public class A {

    private String solve() throws IOException {
        int n = nextInt();
        long[] x = new long[n];
        long[] y = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = nextInt();
        }
        for (int i = 0; i < n; i++) {
            y[i] = nextInt();
        }
        Arrays.sort(x);
        Arrays.sort(y);
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += x[i] * y[n - 1 - i];
        }
        return "" + ans;
    }

    private BufferedReader reader;

    private StringTokenizer tt = new StringTokenizer("");

    private String nextToken() throws IOException {
        while (!tt.hasMoreTokens()) {
            tt = new StringTokenizer(reader.readLine());
        }
        return tt.nextToken();
    }

    private int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    private void run() throws IOException {
        reader = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter writer = new PrintWriter(new File("A-large.out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
        } finally {
            reader.close();
            writer.close();
        }
    }

    public static void main(String[] args) {
        try {
            new A().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}