import java.io.*;
import java.util.*;

public class A {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    long getLevel(long budget, long bets[]) {
        long min = 0;
        long max = budget + 1;
        while (min + 1 < max) {
            long mid = (min + max) / 2;
            long need = 0;
            for (int i = 0; i < bets.length; i++) {
                if (bets[i] < mid) {
                    need += mid - bets[i];
                }
            }
            if (need > budget) {
                max = mid;
            } else {
                min = mid;
            }
        }
        return min;
    }

    double getProfit(long budget, long bets[], int minCol, long level) {
        if (level <= 0) {
            return -1;
        }
        long need1 = 0;
        for (int i = 0; i < minCol; i++) {
            if (bets[i] > level) {
                return -1;
            }
            need1 += level - bets[i];
        }
        long need2 = 0;
        for (int i = minCol; i < 37; i++) {
            if (bets[i] < level + 1) {
                need2 += level + 1 - bets[i];
            }
        }
        if (need1 + need2 > budget) {
            return -1;
        }
        double profit = level * 36.0 * need1 / (level * minCol) - (need1 + need2);
        // out.println("budget=" + budget + " minCol=" + minCol + " level=" + level + " need1=" + need1 + " need2=" + need2 + " profit = " + profit);
        return profit;
    }

    double solveOne() {
        long budget = in.nextLong();
        int nBets = in.nextInt();
        long bets[] = new long[37];
        for (int i = 0; i < nBets; i++) {
            bets[i] = in.nextLong();
        }
        Arrays.sort(bets);
        if (bets.length == 1) {
            return 0;
        }
        Assert.check(bets.length > 1);
        long maxLevel = getLevel(budget, bets);
        double max = 0;
        for (int minCol = 1; minCol <= 37; minCol++) {
            for (int i = 0; i < bets.length; i++) {
                max = Math.max(max, getProfit(budget, bets, minCol, bets[i] - 1));
                max = Math.max(max, getProfit(budget, bets, minCol, bets[i]));
                max = Math.max(max, getProfit(budget, bets, minCol, bets[i] + 1));
            }
            max = Math.max(max, getProfit(budget, bets, minCol, maxLevel - 1));
            max = Math.max(max, getProfit(budget, bets, minCol, maxLevel));
            max = Math.max(max, getProfit(budget, bets, minCol, maxLevel + 1));
        }
        /*
        double max2 = max;
        double maxLevel2 = 0;
        for (int minCol = 1; minCol <= 37; minCol++) {
            for (int level = 0; level <= 1000; level++) {
                double profit = getProfit(budget, bets, minCol, level);
                if (profit > max2) {
                    max2 = profit;
                    maxLevel2 = level;
                }
            }
        }
        if (max2 > max) {
            out.println("wrong: max = " + max + " max2 = " + max2 + " maxLevel2 = " + maxLevel2);
        }
        */
        return max;
    }

    void solve() {
        int nTests = in.nextInt();
        for (int i = 1; i <= nTests; i++) {
            out.println("Case #" + i + ": " + solveOne());
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new A().run();
    }
}