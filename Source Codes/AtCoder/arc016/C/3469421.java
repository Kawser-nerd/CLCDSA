import java.util.*;
import java.util.stream.IntStream;

public class Main {
    static int n;
    static int m;
    static double[] memo = new double[1024 * 4];
    static int[][] I = new int[100][100];
    static int[][] P = new int[100][100];
    static int[] cost = new int[10];
    static int C[] = new int[10];
    static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 0; i < m; i++) {
            C[i] = sc.nextInt();
            cost[i] = sc.nextInt();
            for (int j = 0; j < C[i]; j++) {
                I[i][j] = sc.nextInt()-1;
                P[i][j] = sc.nextInt();
            }
        }
        Arrays.fill(memo, 1e9);
        memo[(1 << n) - 1] = 0;
        for (int s = (1 << n) - 1; s >= 0; s--) {
            for (int i = 0; i < m; i++) {
                double sum = cost[i];
                double k = 0;
                for (int j = 0; j < C[i]; j++) {
                    if (!getBit(s, I[i][j])) {
                        sum += memo[setBit(s, I[i][j])] * P[i][j] / 100.0;
                    }
                    else {
                        k += P[i][j];
                    }
                }
                memo[s] = Math.min(memo[s], sum * 100.0 / (100 - k));
            }
        }

        System.out.println(memo[0]);
    }


    static boolean getBit(int num, int i) {
        return ((num & (1 << i)) != 0);
    }

    static int setBit(int num, int i) {
        return num | (1 << i);
    }
}