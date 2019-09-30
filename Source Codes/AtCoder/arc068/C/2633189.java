import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    int n, m;
    List<List<Integer>> lists;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        m = sc.nextInt();
        lists = new ArrayList<>();
        for (int i = 0; i <= m; i++) {
            lists.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            lists.get(r - l + 1).add(l);
        }
        solve();
    }

    void solve() {
        int lengthy = n;
        FenwickTree ft = new FenwickTree(m);
        for (int d = 1; d <= m; d++) {
            int ans = 0;
            for (int i = d; i <= m; i += d) {
                ans += ft.rangeSum(i);
            }
            ans += lengthy;
            System.out.println(ans);
            for (int start : lists.get(d)) {
                ft.update(start, 1);
                ft.update(start + d, -1);
            }
            lengthy -= lists.get(d).size();
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

    class FenwickTree {
        private final int[] tree;
        private final int N;

        FenwickTree(int N){
            this.tree = new int[N + 1];
            this.N = N;
        }

        private int lsb(int x){
            return x & (-x);
        }

        void update(int position, int key){
            while (position <= N){
                tree[position] += key;
                position += lsb(position);
            }
        }

        int rangeSum(int position){
            int sum = 0;
            while (position >= 1){
                sum += tree[position];
                position -= lsb(position);
            }

            return sum;
        }

        int rangeSum(int x, int y){
            return rangeSum(y) - rangeSum(x - 1);
        }
    }

}