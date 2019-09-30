import java.io.*;
import java.util.StringTokenizer;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.math.BigInteger;

/**
 * @author Ivan Romanov
 */
public class C {

    private static BigDecimal sq5;

    private static final int ITER = 200;

    private static final int SCALE = 200;

    static {
        sq5 = new BigDecimal(1);
        for (int i = 0; i < ITER; i++) {
            sq5 = new BigDecimal(5).divide(sq5, SCALE, RoundingMode.HALF_UP).add(sq5).divide(new BigDecimal(2), SCALE, RoundingMode.HALF_UP);
        }
    }

    private String solve() throws IOException {
        int n = nextInt();
        BigDecimal a = new BigDecimal(3).add(sq5);
        a = a.pow(n);
        String x = "000" + a.toBigInteger().toString();
        x = x.substring(x.length() - 3);
        return x;
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
        reader = new BufferedReader(new FileReader("C-small.in"));
        PrintWriter writer = new PrintWriter(new File("C-small.out"));
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
            new C().run();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}