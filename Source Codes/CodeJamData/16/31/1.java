import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {
    public static void main(String[] args) {
        new A().run();
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

    public class Pair implements Comparable<Pair> {
        int x, id;

        public Pair(int x, int id) {
            this.x = x;
            this.id = id;
        }

        public int compareTo(Pair p) {
            return x - p.x;
        }
    }

    public void solve() throws IOException {
        int n = nextInt();
        Pair[] p = new Pair[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Pair(nextInt(), i);
        }
        Arrays.sort(p);

        while (p[p.length - 1].x > p[p.length - 2].x) {
            out.print((char) (p[p.length - 1].id + 'A') + " ");
            p[p.length - 1].x--;
        }
        for (int i = 0; i < p.length - 2; i++) {
            while (p[i].x > 0) {
                out.print((char) (p[i].id + 'A') + " ");
                p[i].x--;
            }
        }
        while (p[p.length - 1].x > 0) {
            out.print((char) (p[p.length - 2].id + 'A') + "" + (char) (p[p.length - 1].id + 'A') + " ");
            p[p.length - 1].x--;
        }
        out.println();
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
