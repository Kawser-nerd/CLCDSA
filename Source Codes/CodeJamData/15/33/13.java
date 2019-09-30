import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class C {
    public static void main(String[] args) {
        new C().run();
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

    public void solve() throws IOException {
        int c = nextInt();
        int d = nextInt();
        int v = nextInt();

        int[] denom = new int[d];
        for (int i = 0; i < denom.length; i++) {
            denom[i] = nextInt();
        }

        int pos = 0;

        int ans = 0;
        long max = 0;
        while (max < v) {
            while (pos < denom.length && max + 1 >= denom[pos]) {
                max = 1L * denom[pos] * c + max;
                pos++;
            }
            if (max < v) {
                ans++;
                max = 1L * (max + 1) * c + max;
            }
        }

        out.println(ans);
    }

    public void run() {
        try {
            br = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int t = nextInt();
            for (int i = 0; i < t; i++) {
                out.print(String.format("Case #%d: ", i + 1));
                solve();
            }

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
