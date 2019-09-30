package com.forthgo.google.g2012r1c;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Created by Xan Gregg.
 * Date: 5/6/12
 */
public class ProblemC {
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("C.in"));
            PrintWriter out = new PrintWriter(new FileWriter("C.out"));
//            PrintWriter out = new PrintWriter(System.out);
            int n = in.nextInt();
            in.nextLine();
            for (int i = 0; i < n; i++) {
                int nn = in.nextInt();
                int mm = in.nextInt();
                long k = solve(in, nn, mm);
                out.printf("Case #%d: %d%n", i + 1, k);
                out.flush();
            }
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }

    static Map<PositionPair, Long> memo;
    static long[][] count;
    static int[][] type;

    private static long solve(Scanner in, int n, int m) {
        count = new long[2][];
        count[0] = new long[n];
        count[1] = new long[m];
        type = new int[2][];
        type[0] = new int[n];
        type[1] = new int[m];

        for (int i = 0; i < n; i++) {
            count[0][i] = in.nextLong();
            type[0][i] = in.nextInt();
        }
        for (int i = 0; i < m; i++) {
            count[1][i] = in.nextLong();
            type[1][i] = in.nextInt();
        }
        memo = new HashMap<PositionPair, Long>();
        return getBest(new PositionPair(0, 0, 0, 0));
    }

    private static long getBest(PositionPair pp) {
        if (memo.containsKey(pp))
            return memo.get(pp);
        if (pp.index0 == count[0].length || pp.index1 == count[1].length)
            return 0;
        long best = 0;
        if (type[0][pp.index0] == type[1][pp.index1]) {
            long c0 = count[0][pp.index0] - pp.offset0;
            long c1 = count[1][pp.index1] - pp.offset1;
            best = Math.min(c0, c1);
            if (c0 == c1) {
                best += getBest(new PositionPair(pp.index0 + 1, 0, pp.index1 + 1, 0));
            }
            else if (c0 < c1) {
                best += getBest(new PositionPair(pp.index0 + 1, 0, pp.index1, pp.offset1 + c0));
            }
            else {
                best += getBest(new PositionPair(pp.index0, pp.offset0 + c1, pp.index1 + 1, 0));
            }
        }
        else {
            long a = getBest(new PositionPair(pp.index0 + 1, 0, pp.index1, pp.offset1));
            long b = getBest(new PositionPair(pp.index0, pp.offset0, pp.index1 + 1, 0));
            best = Math.max(a, b);
        }
        memo.put(pp, best);
        return best;
    }

    static class PositionPair {
        public int index0;
        public int index1;
        public long offset0;
        public long offset1;

        public PositionPair(int index0, long offset0, int index1, long offset1) {
            this.index0 = index0;
            this.offset0 = offset0;
            this.index1 = index1;
            this.offset1 = offset1;
        }

        @Override
        public int hashCode() {
            return (int)(index0 ^ index1 ^ offset0 ^ offset1);
        }

        @Override
        public boolean equals(Object o) {
            if (!(o instanceof PositionPair))
                return false;
            PositionPair pp = (PositionPair) o;
            return pp.index0 == index0 && pp.index1 == index1 && pp.offset0 == offset0 && pp.offset1 == offset1;
        }
    }

}

