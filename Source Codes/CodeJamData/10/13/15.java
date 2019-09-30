import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class C {

    private static final String PROBLEM = "C";

    //private static final String TEST = "small-attempt0";
    private static final String TEST = "large";

    private String solve() throws IOException {
        int a1 = nextInt();
        int a2 = nextInt();
        int z1 = nextInt();
        int z2 = nextInt();

        long cnt = 0;
        double phi = (Math.sqrt(5.0) - 1) * 0.5;
        for (int i = a1; i <= a2; i++) {
            int b = (int) Math.round(i * phi);
            int b1 = Math.max(1, b - 3);
            int b2 = Math.max(1, b + 3);
            int first0 = getRes(i, b1, b2, false);

            b = (int) Math.round(i / phi);
            b1 = Math.max(1, b - 3);
            b2 = Math.max(1, b + 3);
            int last0 = getRes(i, b1, b2, true) - 1;

            int right = Math.min(first0, z2 + 1);
            if (z1 < right) {
                cnt += right - z1;
            }
            int left = Math.max(z1 - 1, last0);
            if (last0 < z2) {
                cnt += z2 - left;
            }
        }
        return "" + cnt;
    }

    private static int getRes(int i, int b1, int b2, boolean target) {

        boolean wasNot = i == 1;
        for (int j = b1; j <= b2; j++) {
            int x = i;
            int y = j;
            boolean win = true;
            while (x < 2 * y && y < 2 * x) {
                if (x > y) {
                    x -= y;
                } else {
                    y -= x;
                }
                win = !win;
            }
            wasNot |= win != target;
            if (win == target && wasNot) {
                return j;
            }
        }
        throw null;
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
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + TEST + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + TEST + ".out"));
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