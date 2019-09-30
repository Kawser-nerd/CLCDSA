import java.io.*;
import java.util.*;

public class C {
    PrintWriter out;
    Scanner in;

    public static void main(String[] args) throws Exception {
        new C().solve();
    }

    int m, q;
    double[][] data;

    List<Double> buf;
    int pos;

    void go(int p, double res) {
        if (p == q) {
            buf.add(res);
            return;
        }
        for (int i = 0; i < 4; ++i) {
            go(p + 1, data[p][i] * res);
        }
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream("c.out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("c.in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");
            m = in.nextInt();
            q = in.nextInt();
            data = new double[q][4];
            for (int i = 0; i < q; ++i) {
                for (int j = 0; j < 4; ++j) {
                    data[i][j] = in.nextDouble();
                }
            }

            buf = new ArrayList();
            go(0, 1);
            Collections.sort(buf);
            double ans = 0;
            for (int i = buf.size() - 1; i >= 0 && buf.size() - i <= m; --i) {
                ans += buf.get(i);
            }

            out.println(ans);
        }

        out.close();
    }
}
