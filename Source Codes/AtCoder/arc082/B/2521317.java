import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    int n;
    int[] ps;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        ps = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            ps[i] = sc.nextInt();
        }
        solve();
    }

    void solve() {
        boolean[] bads = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            if (ps[i] == i) {
                bads[i] = true;
            }
        }
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (ps[i] == i) {
                swap(ps, i, i + 1);
                count++;
            }
        }
        if (ps[n] == n) {
            count++;
        }
        System.out.println(count);
    }

    void swap(int[] ps, int i, int j) {
        int temp = ps[i];
        ps[i] = ps[j];
        ps[j] = temp;
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