import java.util.*;

public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numCases = sc.nextInt();
        for (int q = 0; q < numCases; q++) {
            int myHealth = sc.nextInt();
            H = myHealth;
            myAttack = sc.nextInt();
            int hisHealth = sc.nextInt();
            hisAttack = sc.nextInt();
            B = sc.nextInt();
            D = sc.nextInt();

            dp = new long[myHealth + 1][hisHealth + 1][101][101];
            healUsed = new boolean[myHealth + 1][hisHealth + 1][101][101];
            for (int i = 0; i < dp.length; i++) {
                for (int j = 0; j < dp[i].length; j++) {
                    for (int k = 0; k < dp[i][j].length; k++) {
                        Arrays.fill(dp[i][j][k], -1);
                    }
                }
            }

            long ans = solve(myHealth, hisHealth, 0, 0);

            System.out.printf("Case #%d: ", q+1);
            if (ans >= INF) {
                System.out.println("IMPOSSIBLE");
            } else {
                System.out.println(ans);
            }

            dp = null;
            healUsed = null;
        }
    }

    static int H;
    static int myAttack;
    static int hisAttack;
    static int B;
    static int D;
    static long[][][][] dp;
    static boolean[][][][] healUsed;
    static long INF = 1L << 50;
    static long solve(final int myHealth, final int hisHealth, final int buffs, final int debuffs) {
        if (dp[myHealth][hisHealth][buffs][debuffs] != -1) {
            return dp[myHealth][hisHealth][buffs][debuffs];
        }

//        dp[myHealth][hisHealth][buffs][debuffs] = INF;

        final int myCurAttack = myAttack + buffs * B;
        final int hisCurAttack = Math.max(0, hisAttack - debuffs * D);
        long min = INF;
        { // Attack!
            int hisNewHealth = hisHealth - myCurAttack;
            int myNewHealth = myHealth - hisCurAttack;
            if (hisNewHealth <= 0) {
                return 1;
            } else if (myNewHealth <= 0) {
            } else {
                min = Math.min(min, 1 + solve(myNewHealth, hisNewHealth, buffs, debuffs));
            }
        }
        if (!healUsed[myHealth][hisHealth][buffs][debuffs]) { // Heal
            int hisNewHealth = hisHealth;
            int myNewHealth = H - hisCurAttack;
            if (hisNewHealth <= 0) {
                return 1;
            } else if (myNewHealth <= 0) {
            } else {
                healUsed[myHealth][hisHealth][buffs][debuffs] = true;
                min = Math.min(min, 1 + solve(myNewHealth, hisNewHealth, buffs, debuffs));
            }
        }
        if (B > 0) { // Buff myself
            int hisNewHealth = hisHealth;
            int myNewHealth = myHealth - hisCurAttack;
            if (hisNewHealth <= 0) {
                return 1;
            } else if (myNewHealth <= 0) {
            } else {
                min = Math.min(min, 1 + solve(myNewHealth, hisNewHealth, buffs + 1, debuffs));
            }
        }
        if (D > 0 && hisCurAttack > 0) { // Debuff myself
            int hisNewAttack = Math.max(0, hisCurAttack - D);
            int hisNewHealth = hisHealth;
            int myNewHealth = myHealth - hisNewAttack;
            if (hisNewHealth <= 0) {
                return 1;
            } else if (myNewHealth <= 0) {
            } else {
                min = Math.min(min, 1 + solve(myNewHealth, hisNewHealth, buffs, debuffs + 1));
            }
        }

        dp[myHealth][hisHealth][buffs][debuffs] = min;
        return min;
    }
}
