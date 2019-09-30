import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    static int R, C;
    static char[][] map;

    static int[] dx = new int[] { -1, 1, 0, 0 };
    static int[] dy = new int[] { 0, 0, -1, 1 };

    static boolean check(int x, int y, int d) {
        x += dx[d];
        y += dy[d];
        while (x >= 0 && x < R && y >= 0 && y < C) {
            if (map[x][y] != '.') {
                return true;
            }
            x += dx[d];
            y += dy[d];

        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        FastScanner scan = new FastScanner(System.in);
        int taskCount = scan.nextInt();
        for (int taskIndex = 1; taskIndex <= taskCount; ++taskIndex) {
            R = scan.nextInt();
            C = scan.nextInt();
            map = new char[R][];
            for (int i = 0; i < R; ++i) {
                map[i] = scan.nextToken().toCharArray();
            }
            Map<Character, Integer> dMap = new HashMap<>();
            dMap.put('^', 0);
            dMap.put('v', 1);
            dMap.put('<', 2);
            dMap.put('>', 3);

            boolean fail = false;
            int res = 0;

            all: for (int i = 0; i < R; ++i) {
                outer: for (int j = 0; j < C; ++j) {
                    if (map[i][j] == '.') {
                        continue;
                    }
                    int d = dMap.get(map[i][j]);
                    if (check(i, j, d)) {
                        continue;
                    } else {
                        for (int k = 0; k < 4; ++k) {
                            if (k == d) {
                                continue;
                            }
                            if (check(i, j, k)) {
                                ++res;
                                continue outer;
                            }
                        }
                        fail = true;
                        break all;
                    }
                }
            }

            if (fail) {
                System.out.println(String.format("Case #%d: IMPOSSIBLE", taskIndex));
            } else {
                System.out.println(String.format("Case #%d: %d", taskIndex, res));
            }
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

    private String next() {
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