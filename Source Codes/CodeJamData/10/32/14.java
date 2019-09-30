import java.io.*;
import java.math.*;
import java.util.*;

/**
 * @author def
 * @version 1.0
 */
public class B {

    public static void main(String args[]) throws IOException {
        new B().solve();
    }

    void solve() throws IOException {
        in = new BufferedReader(new FileReader("B-large.in"));
        out = new PrintWriter("B-large.out");

        int t = Integer.parseInt(in.readLine());
        for (int c = 1; c <= t; ++c) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            long l = Integer.parseInt(st.nextToken());
            long p = Integer.parseInt(st.nextToken());
            long k = Integer.parseInt(st.nextToken());
            int n = 0;
            while (l * k < p) {
                l *= k;
                ++n;
            }
            int cnt = 0;
            while (n > 0) {
                n >>>= 1;
                ++cnt;
            }
            out.println("Case #" + c + ": " + cnt);
        }

        out.close();
    }

    BufferedReader in;
    PrintWriter out;
}