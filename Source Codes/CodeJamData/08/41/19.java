import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

/**
 * @author Ivan Romanov
 */
public class A {
    private static final int BESK = Integer.MAX_VALUE >> 3;

    private String solve() throws IOException {
        int m = nextInt();
        int v = nextInt();

        int[] op = new int[m + 1];
        boolean[] changeable = new boolean[m + 1];
        int[][] cost = new int[m + 1][2];

        for (int[] x : cost) {
            Arrays.fill(x, BESK);
        }

        int internals = (m - 1) / 2;

        for (int i = 1; i <= internals; i++) {
            int g = nextInt();
            int c = nextInt();
            op[i] = g;
            changeable[i] = c == 1;
        }

        for (int i = 1; i <= ((m + 1) / 2); i++) {
            int value = nextInt();
            cost[i + internals][value] = 0;
        }

        for (int i = internals; i >= 1; i--) {
            int costOr = op[i];
            int costAnd = 1 - op[i];
            if (!changeable[i]) {
                costOr *= BESK;
                costAnd *= BESK;
            }
            // cost of getting 0
            cost[i][0] = Math.min(cost[i][0], costOr  + cost[i * 2][0] + cost[i * 2 + 1][0]);
            cost[i][0] = Math.min(cost[i][0], costAnd + cost[i * 2][0] + cost[i * 2 + 1][0]);
            cost[i][0] = Math.min(cost[i][0], costAnd + cost[i * 2][1] + cost[i * 2 + 1][0]);
            cost[i][0] = Math.min(cost[i][0], costAnd + cost[i * 2][0] + cost[i * 2 + 1][1]);
            // cost of getting 1
            cost[i][1] = Math.min(cost[i][1], costAnd + cost[i * 2][1] + cost[i * 2 + 1][1]);
            cost[i][1] = Math.min(cost[i][1], costOr  + cost[i * 2][1] + cost[i * 2 + 1][1]);
            cost[i][1] = Math.min(cost[i][1], costOr  + cost[i * 2][1] + cost[i * 2 + 1][0]);
            cost[i][1] = Math.min(cost[i][1], costOr  + cost[i * 2][0] + cost[i * 2 + 1][1]);
        }
        if (cost[1][v] >= BESK) {
            return "IMPOSSIBLE";
        }
        return "" + cost[1][v];
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