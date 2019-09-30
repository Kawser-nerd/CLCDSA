import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    char[] cs;
    List<Integer> list;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        cs = sc.next().toCharArray();
        solve();
    }

    void solve() {
        list = new ArrayList<>();
        int plus = 0;
        int minus = 0;
        for (int i = cs.length - 1; i >= 0; i--) {
            if (cs[i] == '+') {
                plus++;
            } else if (cs[i] == '-') {
                minus++;
            } else {
                list.add(plus - minus);
            }
        }
        Collections.sort(list);
        long ans = 0;
        for (int i = 0; i < list.size(); i++) {
            if (i * 2 < list.size()) {
                ans -= list.get(i);
            } else {
                ans += list.get(i);
            }
        }
        System.out.println(ans);
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