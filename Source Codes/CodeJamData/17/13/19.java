import org.omg.CORBA.PRIVATE_MEMBER;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main {
    private static StringTokenizer st;
    private static BufferedReader br;
    public static long MOD = 1000000007;
    public static double EPS = 0.000001;

    public static void print(Object x) {
        System.out.println(x + "");
    }
    public static String join(Collection<?> x, String space) {
        if (x.size() == 0) return "";
        StringBuilder sb = new StringBuilder();
        boolean first = true;
        for (Object elt : x) {
            if (first) first = false;
            else sb.append(space);
            sb.append(elt);
        }
        return sb.toString();
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line.trim());
        }
        return st.nextToken();
    }
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }
    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public static int K = 1000;
    public static int B;
    public static int C;
    public static int D;
    public static long WIN = -1;

    public static long state(long Hd, long Hk, long Ad, long Ak) {
        return Hd + Hk*K + Ad*K*K + Ak*K*K*K;
    }
    public static int getHd(long state) {
        return (int) (state % K);
    }
    public static int getHk(long state) {
        return (int) ((state / K) % K);
    }
    public static int getAd(long state) {
        return (int) ((state / (K*K)) % K);
    }
    public static int getAk(long state) {
        return (int) (state / (K*K*K));
    }

    public static List<Long> nextStates(long state) {
        int Hd = getHd(state);
        int Hk = getHk(state);
        int Ad = getAd(state);
        int Ak = getAk(state);
//        print("Checking " + Hd + " " + Hk + " " + Ad + " " + Ak);
        // SPECIAL CASE: REVIVE FOREVER FIXME

        List<Long> states = new ArrayList<>();
        if (Hk - Ad <= 0) {
            // Attack and win
            states.add(WIN);
        } else if (Hd - Ak > 0) {
            // Can survive attack
            // Attack and retaliate
            long state1 = state(Hd - Ak, Hk - Ad, Ad, Ak);
            states.add(state1);
            // Buff and retaliate
            long state2 = state(Hd - Ak, Hk, Ad + B, Ak);
            states.add(state2);
        }

        // Cure
        if (C - Ak > 0) {
//            print("  CURE");
            states.add(state(C - Ak, Hk, Ad, Ak));
        }

        // Debuff
        int Akd = Math.max(0, Ak - D);
        if (Hd - Akd > 0) {
            states.add(state(Hd - Akd, Hk, Ad, Akd));
        }

        return states;
    }

    public static void main(String[] args) throws IOException {
        // br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));

        int T = nextInt();
        for (int t = 1; t <= T; t++) {
            int Hd = nextInt();
            int Ad = nextInt();
            int Hk = nextInt();
            int Ak = nextInt();
            B = nextInt();
            D = nextInt();
            C = Hd;
            Set<Long> states = new HashSet<>();
            states.add(state(Hd, Hk, Ad, Ak));

            int turn = 1;
            boolean won = false;
            while (states.size() > 0) {
                if (turn > 250) break;
//                print(turn);
                Set<Long> next = new HashSet<>();
                for (Long state : states) {
                    next.addAll(nextStates(state));
                }
                for (Long state : next) {
                    if (state == WIN) {
                        won = true;
                    }
                }
                if (won) break;
                states = next;
                turn += 1;
            }

            if (won) {
                System.out.printf("Case #%d: %d%n", t, turn);
            } else {
                System.out.printf("Case #%d: IMPOSSIBLE%n", t);
            }
        }
    }
}
