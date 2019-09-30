
import java.io.PrintStream;
import java.util.*;

public class A {

    private static final Scanner sc = new Scanner(System.in);
    private static final PrintStream out = new PrintStream(System.out);

    int MUL = 101;

    int N, P;

    long cons(byte[] ps, int add) {
        long state = 0;
        for (int p : ps) {
            state = state * MUL + p;
        }
        state = state * P + add;
        return state;
    }

    int split(long state, byte[] ps) {
        int add = (int)(state % P);
        state /= P;
        for (int i = 2 * P - 1; i >= 0; --i) {
            ps[i] = (byte)(state % MUL);
            state /= MUL;
        }
        return add;
    }

    Map<Long, Integer> dp;

    int best(long state) {
        if (dp.containsKey(state))
            return dp.get(state);
        byte[] ps = new byte[2 * P];
        int add = split(state, ps);
        int ans = 0;
        boolean any = false;
        for (int i = 0; i < 2 * P; ++i) {
            if (ps[i] > 0) {
                any = true;
                ps[i]--;
                if (i < P) {
                    if (i <= add) {
                        ans = Math.max(ans, best(cons(ps, add - i)));
                    } else {
                        ans = Math.max(ans, best(cons(ps, P + add - i)));
                    }
                } else {
                    ans = Math.max(ans, best(cons(ps, (P - (i - add) % P) % P)));
                }
                ps[i]++;
            }
        }
        if (any) {
            ans += add == 0 ? 1 : 0;
        }
        dp.put(state, ans);
        return ans;
    }

    private String solve() {
        dp = new HashMap<>();
        N = sc.nextInt();
        P = sc.nextInt();
        int[] G = new int[N];
        byte[] ps = new byte[2 * P];
        for (int i = 0; i < N; ++i) {
            G[i] = sc.nextInt();
            ps[G[i] % P + (G[i] >= P ? P : 0)]++;
        }
        int ans = best(cons(ps, 0));
        return "" + ans;
    }

    private void run() throws Exception {
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            String res = solve();
            out.printf("Case #%d: %s\n", i, res);
            System.err.println(i);
        }
        sc.close();
        out.close();
    }

    public static void main(String args[]) throws Exception {
        new A().run();
    }
}