import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Ivan Romanov
 */
public class A {
    private static final String PROBLEM = "A";

    private static final String SIZE = "large";
    //private static final String SIZE = "small-attempt0";
    //private static final String SIZE = "small-practice";

    private String solve() throws IOException {
        int r = nextInt();
        int c = nextInt();
        char[][] f = new char[r][];
        for (int i = 0; i < r; i++) {
            f[i] = nextToken().toCharArray();
            if (f[i].length != c) {
                throw null;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (f[i][j] == '#') {
                    if (i < r - 1 && j < c - 1 && f[i][j + 1] == '#' &&
                            f[i + 1][j] == '#' && f[i + 1][j + 1] == '#') {
                        f[i][j] = '/';
                        f[i][j + 1] = '\\';
                        f[i + 1][j] = '\\';
                        f[i + 1][j + 1] = '/';
                    } else {
                        return "\nImpossible";
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char[] row : f) {
            sb.append('\n');
            sb.append(row);
        }
        return sb.toString();
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
        reader = new BufferedReader(new FileReader(PROBLEM + "-" + SIZE + ".in"));
        PrintWriter writer = new PrintWriter(new File(PROBLEM + "-" + SIZE + ".out"));
        try {
            int n = nextInt();
            for (int i = 0; i < n; i++) {
                writer.print("Case #" + (i + 1) + ":");
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
