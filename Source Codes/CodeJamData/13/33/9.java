import java.io.*;
import java.util.*;

public class C {

    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    static class Attack {

        int min;
        int max;
        int strength;

        Attack(int min, int max, int strength) {
            this.min = min;
            this.max = max;
            this.strength = strength;
        }
    }

    class AttackList extends ArrayList<Attack> {}

    Scanner in;
    PrintWriter out;

    int getMin(int height[], int minI, int maxI) {
        Assert.check(minI <= maxI);
        int min = Integer.MAX_VALUE;
        for (int i = minI; i <= maxI; i++) {
            min = Math.min(min, height[i]);
        }
        return min;
    }

    void setMin(int height[], int minI, int maxI, int minHeight) {
        Assert.check(minI <= maxI);
        for (int i = minI; i <= maxI; i++) {
            height[i] = Math.max(height[i], minHeight);
        }
    }

    int solveOne() {
        AttackList days[] = new AttackList[676061];
        int nTribes = in.nextInt();
        int height[] = new int[401];
        final int base = 200;
        for (int iTribe = 0; iTribe < nTribes; iTribe++) {
            int firstDay = in.nextInt();
            int nAttacks = in.nextInt();
            int firstMin = in.nextInt();
            int firstMax = in.nextInt();
            int firstStrength = in.nextInt();
            int dDays = in.nextInt();
            int shift = in.nextInt();
            int dStrength = in.nextInt();
            for (int iAttack = 0; iAttack < nAttacks; iAttack++) {
                int day = firstDay + iAttack * dDays;
                int min = firstMin + iAttack * shift;
                int max = firstMax + iAttack * shift;
                int strength = firstStrength + iAttack * dStrength;
                if (days[day] == null) {
                    days[day] = new AttackList();
                }
                days[day].add(new Attack(base + min, base + max - 1, strength));
            }
        }
        int count = 0;
        for (int day = 0; day < days.length; day++) {
            if (days[day] == null) {
                continue;
            }
            for (Attack attack : days[day]) {
                if (getMin(height, attack.min, attack.max) < attack.strength) {
                    count++;
                }
            }
            for (Attack attack : days[day]) {
                setMin(height, attack.min, attack.max, attack.strength);
            }
        }
        return count;
    }

    void solve() {
        int nTests = in.nextInt();
        for (int i = 1; i <= nTests; i++) {
            out.printf("Case #%d: %d%n", i, solveOne());
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
        new C().run();
    }
}
