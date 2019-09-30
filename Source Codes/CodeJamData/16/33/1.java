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
        int j = nextInt();
        int p = nextInt();
        int s = nextInt();
        int k = nextInt();
        out.println(j * p * Math.min(k, s));
        int[][] jcnt = new int[j][s];
        int[][] pcnt = new int[p][s];
        System.err.println(j + " " + p + " " + s + " " + k);
        for (int i = 0; i < j; i++) {
            for (int m = 0; m < p; m++) {
                int t = (i + m) % s;
                for (int l = 0; l < Math.min(k, s); l++) {
                    out.println((i + 1) + " " + (m + 1) + " " + (t + 1));
                    jcnt[i][t]++;
                    pcnt[m][t]++;
                    if (jcnt[i][t] > k) {
                        System.err.println("FAIL!");
                        System.exit(1);
                    }
                    if (pcnt[m][t] > k) {
                        System.err.println("FAIL!");
                        System.exit(1);
                    }
                    t = (t + 1) % s;
                }
            }
        }
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
