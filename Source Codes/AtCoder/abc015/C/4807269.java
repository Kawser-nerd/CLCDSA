import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int[][] T = new int[N][K];
        for (int n = 0; n < N; n++) {
            for (int k = 0; k < K; k++) {
                T[n][k] = sc.nextInt();
            }
        }

        if (dfs(T, N, K, 0, -1)) {
            out.println("Found");
        } else {
            out.println("Nothing");
        }
    }

    public static boolean dfs(int[][] T, int N, int K, int n, int num) {
        if (n == 0) {
            for (int k = 0; k < K; k++) {
                if (dfs(T, N, K, n + 1, T[n][k])) {
                    return true;
                }
            }
        } else if (n < N) {
            for (int k = 0; k < K; k++) {
                if (dfs(T, N, K, n + 1, num ^ T[n][k])) {
                    return true;
                }
            }
        } else { // n == N
            if (num == 0) {
                return true;
            }
        }

        return false;
    }
}