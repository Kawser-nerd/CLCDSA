import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    int n, z, w;
    int[] as;
    int[][][][] memo;
    Map<Integer, Integer> map;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        z = sc.nextInt();
        w = sc.nextInt();
        as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        if (n > 1) {
            System.out.println(Math.max(Math.abs(as[n - 1] - w),
                    Math.abs(as[n - 2] - as[n - 1])));
        } else {
            System.out.println(Math.abs(as[0] - w));
        }
        /*
        Integer[] numIndexes = new Integer[n];
        for (int i = 0; i < n; i++) {
            numIndexes[i] = i;
        }
        map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(as[i], numIndexes[i]);
        }
        map.put(z, n);
        map.put(w, n + 1);
        Arrays.sort(numIndexes, (a, b) -> as[a] - as[b]);
        memo = new int[2][n + 1][n + 2][n + 2];
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < memo[k].length; i++) {
                for (int j = 0; j < memo[k][i].length; j++) {
                    Arrays.fill(memo[k][i][j], -1);
                }
            }
        }
        System.out.println(dfs(0, 0, z, w));
        */
    }

    int dfs(int depth, int card, int x, int y) {
        //System.out.println(depth + " " + card + " " + x + " " + map.get(x) + " " + y + " " + map.get(y));
        //System.out.println(memo[depth & 1][card][map.get(x)][map.get(y)]);
        if (memo[depth & 1][card][map.get(x)][map.get(y)] >= 0) {
            return memo[depth & 1][card][map.get(x)][map.get(y)];
        }
        if (card == n) {
            memo[depth & 1][card][map.get(x)][map.get(y)] = Math.abs(x - y);
            return memo[depth & 1][card][map.get(x)][map.get(y)];
        }
        int ret;
        if ((depth & 1) == 1) {
            ret = Integer.MAX_VALUE;
            for (int i = card + 1; i <= n; i++) {
                int temp = dfs(depth + 1, i, x, as[i - 1]);
                if (ret > temp) {
                    ret = temp;
                    memo[depth & 1][card][map.get(x)][map.get(y)] = temp;
                }
            }
        } else {
            ret = 0;
            for (int i = card + 1; i <= n; i++) {
                int temp = dfs(depth + 1, i, as[i - 1], y);
                if (ret < temp) {
                    ret = temp;
                    memo[depth & 1][card][map.get(x)][map.get(y)] = temp;
                }
            }
        }
        return ret;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}