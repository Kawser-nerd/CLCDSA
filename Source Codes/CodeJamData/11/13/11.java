package com.forthgo.google.g2011r1a;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Xan Gregg.
 * Date: 5/20/11
 */
public class C {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            //PrintWriter out = new PrintWriter(new FileWriter("C.out"));
            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            for (int i = 0; i < n; i++) {
                long s = solve(in);
                out.printf("Case #%d: %d%n", i + 1, s);
                out.flush();
            }

        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    static Map<State, Long> memo;
    static int[] alias;
    static int[] rev;

    private static long solve(Scanner in) throws IOException {
        int n = in.nextInt();
        int[] c0 = new int[n];
        int[] s0 = new int[n];
        int[] t0 = new int[n];
        for (int i = 0; i < n; i++) {
            c0[i] = in.nextInt();
            s0[i] = in.nextInt();
            t0[i] = in.nextInt();
        }
        int m = in.nextInt();
        int mn = m + n;
        int[] c = new int[mn];
        int[] s = new int[mn];
        int[] t = new int[mn];
        System.arraycopy(c0, 0, c, 0, n);
        System.arraycopy(s0, 0, s, 0, n);
        System.arraycopy(t0, 0, t, 0, n);
        for (int i = 0; i < m; i++) {
            c[i + n] = in.nextInt();
            s[i + n] = in.nextInt();
            t[i + n] = in.nextInt();
        }

//        List<Integer> hand = new ArrayList<Integer>(mn);
//        for (int i = 0; i < n; i++) {
//            hand.add(i);
//        }
//        alias = new int[mn];
//        rev = new int[mn];
//        int k = 0;
//        for (int i = 0; i < mn; i++) {
//            int found = -1;
//            for (int j = 0; j < k; j++) {
//                if (s[i] == s[j] && t[i] == t[j] && c[i] == c[j]) {
//                    found = j;
//                    break;
//                }
//
//            }
//            if (found < 0) {
//                found = k;
//                rev[k] = i;
//                k++;
//            }
//            alias[i] = found;
//        }
        BitSet hand = new BitSet(mn);
        for (int i = 0; i < n; i++) {
            hand.set(i);
        }
        int top = n;
        int turns = 1;
        memo = new HashMap<State, Long>();

        long score = maxScore(c, s, t, turns, top, hand);
        return score;
    }

    private static long maxScore(int[] c, int[] s, int[] t, int turns, int top, BitSet hand) {
        if (turns == 0)
            return 0;

        State state = new State(turns, top, hand);
        if (!memo.containsKey(state)) {
            hand = (BitSet) hand.clone();

            long score = 0;
            int imax;
            int tmax;
            int cmax;
            int smax;
            int cmin;
            int smin;
            do {
                tmax = 0;
                cmax = 0;
                smax = 0;
                cmin = 0;
                smin = 0;
                imax = -1;
                for (int i = hand.nextSetBit(0); i >= 0; i = hand.nextSetBit(i + 1)) {
                    if (t[i] > tmax || t[i] == tmax && c[i] >= cmax && s[i] >= smax) {
                        tmax = t[i];
                        cmax = c[i];
                        smax = s[i];
                        cmin = c[i];
                        smin = s[i];
                        imax = i;
                    }
                    else if (t[i] == tmax) {
                        cmax = Math.max(cmax, c[i]);
                        smax = Math.max(smax, s[i]);
                        cmin = Math.min(cmin, c[i]);
                        smin = Math.min(smin, s[i]);
                        imax = -1;
                    }
                }
                if (imax >= 0) {
                    hand.clear(imax);
                    int cc = Math.min(c[imax], c.length - top);
                    for (int j = 0; j < cc; j++) {
                        hand.set(top + j);
                    }
                    top += cc;
                    score += s[imax];
                    turns += t[imax] - 1;
                }
            } while (imax >= 0 && turns > 0);

//        if (turns == 0)
//            return score;
            long max = 0;

            if (turns > 0) {
                BitSet played = new BitSet(hand.size());
                nextcard:
                for (int i = hand.nextSetBit(0); i >= 0; i = hand.nextSetBit(i + 1)) {
                    if (t[i] < tmax || t[i] == tmax && c[i] <= cmin && s[i] <= smin) {
                        continue;   // not worth trying
                    }
                    if (t[i] != tmax)
                        tmax+=0;
                    for (int j = played.nextSetBit(0); j >= 0; j = played.nextSetBit(j + 1)) {
                        if (c[i] <= c[j] && s[i] <= s[j]) {
                            continue nextcard;
                        }
                    }
                    BitSet h = (BitSet) hand.clone();
                    h.clear(i);
                    played.set(i);
                    int cc = Math.min(c[i], c.length - top);
                    for (int j = 0; j < cc; j++) {
                        h.set(top + j);
                    }
                    long scorej = s[i] + maxScore(c, s, t, turns + t[i] - 1, top + cc, h);
                    if (scorej > max) {
                        max = scorej;
                    }
                }
            }
            memo.put(state, score + max);
        }
        return memo.get(state);
    }

}

class State {
    public final int turns;
    public final int top;
    public final BitSet hand;

    public State(int f, int t, BitSet h) {
        turns = f;
        top = t;
        hand = h;
    }

    @Override
    public int hashCode() {
        return turns ^ top ^ hand.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof State) {
            State other = (State) obj;
            return turns == other.turns && top == other.top && hand.equals(other.hand);
        }
        return false;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return new State(turns, top, hand);
    }

    @Override
    public String toString() {
        return "(" + turns + ", " + top + "," + hand.toString() + ")";
    }


}