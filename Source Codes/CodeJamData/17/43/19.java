
import java.io.PrintStream;
import java.util.*;

public class C {

    private static final Scanner sc = new Scanner(System.in);
    private static final PrintStream out = new PrintStream(System.out);

    int R, C;

    char[][] arr;

    boolean traverse(boolean[][] visited, int x, int y, int dx, int dy) {
        if (x < 0 || x >= R)
            return true;
        if (y < 0 || y >= C)
            return true;
        if (arr[x][y] == '.') {
            visited[x][y] = true;
            return traverse(visited, x + dx, y + dy, dx, dy);
        } else if (arr[x][y] == '|' || arr[x][y] == '-') {
            return false;
        } else if (arr[x][y] == '\\') {
            return traverse(visited, x + dy, y + dx, dy, dx);
        } else if (arr[x][y] == '/') {
            return traverse(visited, x - dy, y - dx, -dy, -dx);
        }
        return true;
    }

    boolean isOk() {
        boolean[][] visited = new boolean[R][C];
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (arr[i][j] == '|') {
                    if (!traverse(visited, i - 1, j, -1, 0)) return false;
                    if (!traverse(visited, i + 1, j, 1, 0)) return false;
                } else if (arr[i][j] == '-') {
                    if (!traverse(visited, i, j - 1, 0, -1)) return false;
                    if (!traverse(visited, i, j + 1, 0, 1)) return false;
                }
            }
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (arr[i][j] == '.' && !visited[i][j])
                    return false;
            }
        }
        return true;
    }

    private String solve() {
        R = sc.nextInt();
        C = sc.nextInt();
        arr = new char[R][];
        for (int i = 0; i < R; ++i) {
            arr[i] = sc.next().toCharArray();
        }
        List<Integer> xs = new ArrayList<>();
        List<Integer> ys = new ArrayList<>();
        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j) {
                if (arr[i][j] == '-' || arr[i][j] == '|') {
                    xs.add(i);
                    ys.add(j);
                }
            }
        int len = xs.size();
        for (int i = 0; i < (1 << len); ++i) {
            for (int j = 0; j < len; ++j) {
                if ((i & (1 << j)) != 0) {
                    arr[xs.get(j)][ys.get(j)] = '|';
                } else {
                    arr[xs.get(j)][ys.get(j)] = '-';
                }
            }
            if (isOk()) {
                String ans = "POSSIBLE\n";
                for (int q = 0; q < R; ++q)
                    ans += new String(arr[q]) + "\n";
                return ans;
            }
        }
        return "IMPOSSIBLE\n";
    }

    private void run() throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            String res = solve();
            out.printf("Case #%d: %s", i, res);
            System.err.println(i);
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new C().run();
    }
}