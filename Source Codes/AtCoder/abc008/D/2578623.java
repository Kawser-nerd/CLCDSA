import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.StringTokenizer;

public class Main {
    int w, h, n;
    int[] xs, ys;
    Map<Key, Integer> map;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        w = sc.nextInt();
        h = sc.nextInt();
        n = sc.nextInt();
        xs = new int[w];
        ys = new int[h];
        for (int i = 0; i < n; i++) {
            xs[i] = sc.nextInt() - 1;
            ys[i] = sc.nextInt() - 1;
        }
        solve();
    }

    void solve() {
        map = new HashMap<>();
        System.out.println(dfs(new Key(0, 0, w, h)));
    }

    int dfs(Key key) {
        if (map.containsKey(key)) {
            return map.get(key);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (key.lx <= xs[i] && xs[i] < key.rx &&
                    key.ly <= ys[i] && ys[i] < key.ry) {
                int ld = dfs(new Key(key.lx, key.ly, xs[i], ys[i]));
                int lu = dfs(new Key(key.lx, ys[i] + 1, xs[i], key.ry));
                int rd = dfs(new Key(xs[i] + 1, key.ly, key.rx, ys[i]));
                int ru = dfs(new Key(xs[i] + 1, ys[i] + 1, key.rx, key.ry));
                res = Math.max(res, ld + lu + rd + ru + key.rx - key.lx +
                        key.ry - key.ly - 1);
            }
        }
        map.put(key, res);
        return res;
    }

    class Key {
        int lx;
        int ly;
        int rx;
        int ry;

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Key key = (Key) o;
            return lx == key.lx &&
                    ly == key.ly &&
                    rx == key.rx &&
                    ry == key.ry;
        }

        @Override
        public int hashCode() {

            return Objects.hash(lx, ly, rx, ry);
        }

        Key(int lx, int ly, int rx, int ry) {
            this.lx = lx;
            this.ly = ly;
            this.rx = rx;
            this.ry = ry;

        }
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