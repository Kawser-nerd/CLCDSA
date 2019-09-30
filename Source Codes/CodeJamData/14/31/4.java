import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class A {
    private final Scanner in;
    private final PrintWriter out;

    public A(Scanner in, PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    public static void main(String[] args) {
        try (Scanner in = new Scanner(new FileReader(new File("A-large.in")));
             PrintWriter out = new PrintWriter("A-large.out")) {
            new A(in, out).solve();
        } catch (Throwable t) {
            t.printStackTrace();
            System.exit(-1);
        }
    }


    private void solve() {
        int tests = in.nextInt();
        for (int test = 1; test <= tests; ++test) {
            StringTokenizer st = new StringTokenizer(in.next(), "/");

            BigInteger P = new BigInteger(st.nextToken());
            BigInteger Q = new BigInteger(st.nextToken());
            BigInteger d = P.gcd(Q);
            P = P.divide(d);
            Q = Q.divide(d);

            long p = P.longValue();
            long q = Q.longValue();

            out.print("Case #" + test + ": ");

            if (q != Long.highestOneBit(q)) {
                out.println("impossible");
            } else {
                int ans;
                for (ans = 0; p < q; ++ans, q >>= 1);
                out.println(ans);
            }
        }
    }
}
