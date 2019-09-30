// @gilesgardam
import java.util.*;
import static java.lang.Math.*;

public class ProblemA {

    void run() {
        Scanner sc = new Scanner(System.in);
        int numCases = sc.nextInt();
        for (int caseNum = 1; caseNum <= numCases; caseNum++) {
            char[] c = sc.next().toCharArray();
            int N = c.length;
            int L = sc.nextInt();
            boolean[] b = new boolean[N];

            boolean cons = false;
            int start = -1;
            boolean icons;
            ArrayList<Integer> bads = new ArrayList<Integer>();
            bads.add(-10000000);
            for (int i = 0; i <= N; ++i) {
                if (i < N) {
                    icons = is_cons(c[i]);
                }
                else {
                    icons = false;
                }
                if (icons != cons) {
                    if (icons) {
                        start = i;
                    }
                    else {
                        if (i - start >= L) {
                            bads.add(i - L);
                            for (int j = start; j <= i - L; ++j) {
                                b[j] = true;
                            }
                        }
                    }
                }
                cons = icons;
            }
            d("bads");
            for (int x : bads) {
                d(x);
            }
            d("end bads");
            d(b);

            long answer = triangle(N);
            for (int i = 0; i < N; ++i) {
                int prev = i - (L-1);
                if (prev < 0 || !b[prev]) {
                    int j = -Collections.binarySearch(bads, prev)-1;
                    d(j);
                    prev = bads.get(j-1);
                }
                prev = max(prev, -1);
                int sub = i - prev;
                d("taking", i, sub);
                answer -= sub;
            }

            System.out.printf("Case #%d: %d\n", caseNum, answer);
        }
    }

    long triangle(long x) {
        return (x * (x + 1)) / 2;
    }

    boolean is_cons(char c) {
        return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
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
    public ProblemA(String[] args) {
        if (args.length > 0 && args[0].equals("debug")) {
            debug = true;
        }
    }
    public static void main(String[] args) {
        new ProblemA(args).run();
    }
}
