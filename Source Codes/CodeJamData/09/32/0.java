import java.io.*;
import java.util.*;

public class B {
    PrintWriter out;
    Scanner in;
    String testCase = "b2";

    public static void main(String[] args) throws Exception {
        new B().solve();
    }

    long sqr(long a) {
        return a * a;
    }

    double sqrt(double a) {
        if (a < 1E-8) {
            return 0;
        } else {
            return Math.sqrt(a);
        }
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.ENGLISH);
        out = new PrintWriter(new FileOutputStream(testCase + ".out"));
        in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(testCase + ".in"))));

        int N = in.nextInt();
        for (int t = 1; t <= N; ++t) {
            out.print("Case #" + t + ": ");

            int n = in.nextInt();

            long x = 0, y = 0, z = 0, vx = 0, vy = 0, vz = 0;
            for (int i = 0; i < n; ++i) {
                x += in.nextInt();
                y += in.nextInt();
                z += in.nextInt();
                vx += in.nextInt();
                vy += in.nextInt();
                vz += in.nextInt();
            }

            long a = sqr(vx) + sqr(vy) + sqr(vz);
            long b = 2 * (x * vx + y * vy + z * vz);
            long c = sqr(x) + sqr(y) + sqr(z);
            double time;
            if (a != 0) {
                time = -b / (2.0 * a);
            } else {
                time = 0;
            }
            if (time < 0) {
                time = 0;
            }
            double d = sqrt((a * time * time + b * time + c)) / n;
//            if (t == 19) {
//                System.out.println(a + " " + b + " " + c + "     " + (a * time * time + b * time + c));
//            }

            out.println(d + " " + time);
        }

        out.close();
    }
}
// 2 4 6
// 6 4 2
// 1 0 -1
// 0 0 -1
// 9 8 6
// 81 + 64 + 36
// 181