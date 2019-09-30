import java.io.*;
import java.util.*;

public class D {
    PrintWriter out;
    Scanner in;
    int[] DX = {0, -1, -1, -1, 0, 1, 1, 1};
    int[] DY = {1, 1, 0, -1, -1, -1, 0, 1};

    public static void main(String[] args) throws Exception {
        new D().solve();
    }

    int n, m;
    Map<String, Boolean> mem = new HashMap();
    Boolean go(char[][] map) {
        String key = "";
        for (char[] row : map) {
            key += new String(row);
        }
        if (mem.containsKey(key)) {
            return mem.get(key);
        }

        int ki = -1, kj = -1;
        for (int i = 0; i < n && ki < 0; ++i) {
            for (int j = 0; j < m; ++j) {
                if (map[i][j] == 'K') {
                    map[i][j] = '#';
                    ki = i;
                    kj = j;
                    break;
                }
            }
        }

        boolean ans = false;
        for (int t = 0; t < 8; ++t) {
            int ni = ki + DX[t];
            int nj = kj + DY[t];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                continue;
            }
            if (map[ni][nj] == '#') {
                continue;
            }
            map[ni][nj] = 'K';
            boolean res = go(map);
            map[ni][nj] = '.';
            if (!res) {
                ans = true;
                break;
            }
        }

        mem.put(key, ans);
        map[ki][kj] = 'K';
        return ans;
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream("d.out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("d.in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");

            n = in.nextInt();
            m = in.nextInt();
            char[][] map = new char[n][];
            for (int i = 0; i < n; ++i) {
                map[i] = in.next().toCharArray();
            }

            boolean ans = go(map);
            if (ans) {
                out.println("A");
            } else {
                out.println("B");                
            }
        }

        out.close();
    }
}
