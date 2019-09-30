import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class C {

    private static final int[] dx = {0, 1, 0, -1};
    private static final int[] dy = {1, 0, -1, 0};

    private static final String PROBLEM = "C";

    private static final String TEST = "small-attempt0";

    private static final int BASE = 100;

    private static final int PLUS = 350;

    private static final int SIZE = BASE + PLUS;
    //private static final String TEST = "large";

    private String solve() throws IOException {
        int w = nextInt();
        int q = nextInt();
        char[][] a = new char[w][];
        for (int i = 0; i < w; i++) {
            a[i] = nextToken().toCharArray();
        }

        String[][][] d = new String[w][w][SIZE];
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w; j++) {
                if (a[i][j] >= '0') {
                    d[i][j][a[i][j] + BASE - '0'] = "" + a[i][j];
                }
            }
        }
        int count = 0;
        while (true) {
            count++;
            boolean updated = false;
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < w; j++) {
                    if (a[i][j] >= '0') {
                        for (int o1 = 0; o1 < 4; o1++) {
                            if (i + dx[o1] >= 0 && i + dx[o1] < w && j + dy[o1] >= 0 && j + dy[o1] < w) {
                                int sign = (a[i + dx[o1]][j + dy[o1]] == '-' ? -1 : 1);
                                for (int o2 = 0; o2 < 4; o2++) {
                                    int newI = i + dx[o1] + dx[o2];
                                    int newJ = j + dy[o1] + dy[o2];
                                    if (newI >= 0 && newI < w && newJ >= 0 && newJ < w) {
                                        for (int v = 0; v < SIZE; v++) {
                                            if (d[i][j][v] != null) {
                                                int newV = v + sign * (a[newI][newJ] - '0');
                                                if (newV >= 0 && newV < SIZE) {
                                                    String oldD = d[newI][newJ][newV];
                                                    if (oldD == null || d[i][j][v].length() + 2 <= oldD.length()) {
                                                        String newD = d[i][j][v] + a[i + dx[o1]][j + dy[o1]] + "" + a[newI][newJ];
                                                        if (oldD == null || (oldD.length() > newD.length() ||
                                                                (oldD.length() == newD.length() && oldD.compareTo(newD) > 0))) {
                                                            d[newI][newJ][newV] = newD;
                                                            updated = true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!updated) {
                break;
            }
        }
        System.err.println(count + " updates");
        String[] ans = new String[SIZE];
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < w; j++) {
                for (int v = 0; v < SIZE; v++) {
                    String oldD = ans[v];
                    String newD = d[i][j][v];
                    if (newD == null) {
                        continue;
                    }
                    if (oldD == null || (oldD.length() > newD.length() ||
                            (oldD.length() == newD.length() && oldD.compareTo(newD) > 0))) {
                        ans[v] = newD;
                    }
                }
            }
        }
        StringBuilder buf = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int query = nextInt();
            buf.append("\n").append(ans[query + BASE]);
        }
        return buf.toString();
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
            long time = System.currentTimeMillis();
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ": ");
                writer.print(solve());
                writer.println();
            }
            System.err.println(System.currentTimeMillis() - time + " ms");
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