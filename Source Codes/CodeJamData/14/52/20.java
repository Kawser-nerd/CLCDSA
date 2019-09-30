package Round3;

import java.util.Arrays;
import java.util.Scanner;

public class B {
    static int[][][][] DP;
    static int[] H;
    static int[] G;
    static int n;
    static int P, Q;

    public static int get(int index, int missed, int turn, int monster) {
        if (index == n)
            return 0;
        if (DP[index][missed][turn][monster] != -1)
            return DP[index][missed][turn][monster];
        int max = Integer.MIN_VALUE;
        if (monster == 0 && missed * P >= H[index]) {
            int hits = (int) Math.ceil(H[index] * 1.0 / P);
            max = Math.max(max,
                    G[index] + get(index + 1, missed - hits, turn, 0));
        }
        if (turn == 1) {
            if ((monster + 1) * Q >= H[index])
                max = Math.max(max, get(index + 1, missed, 0, 0));
            else
                max = Math.max(
                        max,
                        DP[index][missed][turn][monster] = get(index, missed,
                                0, monster + 1));
        } else {
            max = Math.max(max, get(index, missed + 1, 1, monster));
            if (monster * Q + (missed + 1) * P >= H[index]) {
                int hits = (int) Math.ceil((H[index] - monster * Q) * 1.0 / P);
                max = Math.max(max,
                        G[index] + get(index + 1, missed - hits + 1, 1, 0));
            }
        }
        return DP[index][missed][turn][monster] = max;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int _ = 1; _ <= t; _++) {
            P = in.nextInt();
            Q = in.nextInt();
            n = in.nextInt();
            H = new int[n];
            G = new int[n];
            for (int i = 0; i < n; i++) {
                H[i] = in.nextInt();
                G[i] = in.nextInt();
            }
            DP = new int[n][n * 10 + 10][2][12];
            for (int i = 0; i < DP.length; i++)
                for (int j = 0; j < DP[0].length; j++)
                    for (int k = 0; k < DP[0][0].length; k++)
                        Arrays.fill(DP[i][j][k], -1);
            System.out.println("Case #" + _ + ": " + get(0, 0, 0, 0));
        }
    }
}
