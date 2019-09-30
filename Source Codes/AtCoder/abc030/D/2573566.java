import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    int n, a;
    BigInteger k;
    int[] bs;

    public static void main(String args[]) {
        new Main().run();
    }

    void run() {
        FastReader sc = new FastReader();
        n = sc.nextInt();
        a = sc.nextInt() - 1;
        k = new BigInteger(sc.next());
        bs = new int[n];
        for (int i = 0; i < n; i++) {
            bs[i] = sc.nextInt() - 1;
        }
        solve();
    }

    void solve() {
        int[] visited = new int[n];
        int b = a;
        int count = 1;
        int length;
        while(true) {
            if (visited[a] > 0) {
                length = count - visited[a];
                break;
            }
            visited[a] = count++;
            a = bs[a];
        }
        int searchLength = 0;
        if (k.compareTo(new BigInteger(Integer.toString(count))) < 0) {
            searchLength = k.intValue();
        } else {
            k = k.subtract(new BigInteger(Integer.toString(count)));
            k = k.mod(new BigInteger(Integer.toString(length)));
            int mod = k.intValue();
            searchLength = mod + visited[a];
        }
        for (int i = 0; i < searchLength; i++) {
            b = bs[b];
        }
        System.out.println(b + 1);
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