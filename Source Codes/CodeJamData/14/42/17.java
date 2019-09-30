import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B implements Runnable {
    public static void main(String[] args) {
        new Thread(new B()).run();
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

    public void solve() throws IOException {
        int n = nextInt();

        int ans = 0;
        int[] p = new int[n];
        int[] l = new int[n];
        int[] v = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = nextInt();
            v[i] = p[i];
            l[i] = i;
            for (int j = 0; j < i; j++) {
                if (p[i] > p[j])
                    l[i]--;
            }
        }

        Arrays.sort(v);
        for (int i = 0; i < n; i++) {
            p[i] = Arrays.binarySearch(v, p[i]);
            ans += Math.min(l[i], n - p[i] - l[i] - 1);
        }

        out.println(ans);

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
