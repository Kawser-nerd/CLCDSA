import java.io.*;
import java.util.*;

/**
 * @author def
 * @version 1.0
 */
public class A {

    public static void main(String args[]) throws IOException {
        new A().solve();
    }

    void solve() throws IOException {
        in = new BufferedReader(new FileReader("A-large.in"));
        out = new PrintWriter("A-large.out");

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            int n = Integer.parseInt(in.readLine());
            Wire[] w = new Wire[n];
            for (int i = 0; i < n; ++i) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                w[i] = new Wire();
                w[i].a = Integer.parseInt(st.nextToken());
                w[i].b = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(w);
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (w[j].b < w[i].b) ++cnt;
                }
            }
            out.println("Case #" + c + ": " + cnt);
        }
                                                                            
        out.close();
    }

    class Wire implements Comparable<Wire> {
        int a, b;

        public int compareTo(Wire o) {
            return a - o.a;
        }
    }

    BufferedReader in;
    PrintWriter out;
}