// @gilesgardam
import java.util.*;
import static java.lang.Math.*;

public class ProblemB {

    void run() {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            int X = sc.nextInt();
            int Y = sc.nextInt();
            int XX = abs(X);
            int YY = abs(Y);
            int a = min(XX, YY);
            int b = max(XX, YY);
            boolean x_toggle = X < 0;
            boolean y_toggle = Y < 0;
            boolean xy_toggle = (a != XX);
            int[] p = get_path(a, b);
            int N = p.length;

            if (xy_toggle) {
                for (int i = 0; i < N; ++i) {
                    p[i] = p[i] ^ 2;
                }
            }
            if (x_toggle) {
                for (int i = 0; i < N; ++i) {
                    if ((p[i] & 2) == 2) {
                        p[i] = p[i] ^ 1;
                    }
                }
            }
            if (y_toggle) {
                for (int i = 0; i < N; ++i) {
                    if ((p[i] & 2) == 0) {
                        p[i] = p[i] ^ 1;
                    }
                }
            }

            char[] c = new char[N-1];
            for (int i = 0; i < N-1; ++i) {
                c[i] = get_char(p[i+1]);
            }

            System.out.printf("Case #%d: %s\n", caseNum, new String(c));
        }
    }

    char get_char(int p) {
        char[] c = {'N', 'S', 'E', 'W'};
        return c[p];
    }


    int triangle(int x) {
        return (x * (x + 1)) / 2;
    }

    int[] get_path(int X, int Y) {
        // assume 0 <= a <= b
        // all entries 0, 1, 2 or 3
        // 1's bit is 0 = +ve, 1 = -ve
        // 2's bit is 0 = Y, 1 = X
        int T = X + Y;
        int n = ((int) sqrt(2 * T)) - 5;
        while (n < 0 || triangle(n) < T || (triangle(n) - T) % 2 == 1) {
            ++n;
        }
        int gap = triangle(n) - T;
        int missing = gap / 2;

        int[] ret = new int[n+1];
        int missigno = 3;
        if (X == 0) {
            missigno = 1;
        }
        if (missing <= n) {
            ret[missing] = missigno; // neg X
        }
        else {
            if (missing % 2 == 0) {
                ret[missing / 2 - 1] = missigno;
                ret[missing / 2 + 1] = missigno;
            }
            else {
                ret[missing / 2] = missigno;
                ret[missing / 2 + 1] = missigno;
            }
        }

        int cur = n;
        int x = X;
        if (x > 0) {
            x += missing;
        }
        while (x >= cur && cur >= 1) {
            if (ret[cur] == 0) {
                x -= cur;
                ret[cur] = 2; // pos X
            }
            --cur;
        }
        if (x > 0) {
            if (ret[x] == 0) {
                // hopefully only happens if we hit missing...
                ret[x] = 2;
            }
            else {
                if (x <= 2) {
                    ++cur;
                    ret[cur] = 0;
                    ret[cur-x] = 2;
                    ret[2 * x] = 2;
                }
                else {
                    ret[x-1] = 2;
                    ret[1] = 2;
                }
            }
        }
        return ret;
    }

    boolean debug = false;
    void p(String f, Object...params) {
        System.out.printf(f, params);
    }
    void d(Object...params) {
        if (debug) {
            p("DEBUG: %s\n", Arrays.deepToString(params));
        }
    }
    void die() {
        throw new RuntimeException();
    }
    public ProblemB(String[] args) {
        if (args.length > 0 && args[0].equals("debug")) {
            debug = true;
        }
    }
    public static void main(String[] args) {
        new ProblemB(args).run();
    }
}
