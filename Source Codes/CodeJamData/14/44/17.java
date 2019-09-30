import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D implements Runnable {
    public static void main(String[] args) {
        new Thread(new D()).run();
    }

    BufferedReader br;
    StringTokenizer in;
    PrintWriter out;

    public String nextToken() throws IOException {
        while (in == null || !in.hasMoreTokens()) {
            in = new StringTokenizer(br.readLine());
        }

        return in.nextToken();
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public int calc(ArrayList<String> l) {
        Collections.sort(l);

        int ans = 0;
        String prev = "";
        for (String x : l) {
            int i = 0;
            while (i < x.length() && i < prev.length() && x.charAt(i) == prev.charAt(i)) {
                i++;
            }

            ans += x.length();
            ans -= i;

            prev = x;
        }
        return ans + 1;
    }

    public void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();

        String[] c = new String[n];
        for (int i = 0; i < n; i++) {
            c[i] = nextToken();
        }

        int z = 0;
        int max = 0;
        up:for (int i = 0; i < Math.pow(m, n); i++) {
            ArrayList<String>[] h = new ArrayList[m];

            for (int j = 0; j < m; j++) {
                h[j] = new ArrayList<String>();
            }

            int k = i;
            for (int j = 0; j < n; j++) {
                h[k % m].add(c[j]);
                k /= m;
            }

            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (h[j].size() == 0)
                    continue up;
                cnt += calc(h[j]);
            }

            if (cnt == max) {
                z++;
            }

            if (cnt > max) {
                max = cnt;
                z = 1;
            }
        }

        out.println(max + " " + z);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int t = nextInt();
            for (int i = 0; i < t; i++) {
                out.print("Case #" + (i + 1) + ": ");
                solve();
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
    }
}
