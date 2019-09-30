import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        new Main().compute();
    }

    void compute() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        boolean[][] info = new boolean[N][N];
        for (int i = 0; i < M; i++) {
            info[sc.nextInt() - 1][sc.nextInt() - 1] = true;
        }
        long[] dp = new long[(int) Math.pow(2, N)];
        boolean[] flag = new boolean[(int) Math.pow(2, N)];
        dp[0] = 1L;
        flag[0] = true;
        Queue<Integer> que = new ArrayDeque<>();
        que.add(0);
        while (!que.isEmpty()) {
            int cur = que.poll();
            check:
            for (int i = 0; i < N; i++) {
                if ((cur >> i & 1) == 1) {
                    continue;
                }
                for (int j = 0; j < N; j++) {
                    if ((cur >> j & 1) == 1 && info[i][j]) {
                        continue check;
                    }
                }
                dp[cur + (1 << i)] += dp[cur];
                if (!flag[cur + (1 << i)]) {
                    que.add(cur + (1 << i));
                    flag[cur + (1 << i)] = true;
                }
            }
        }
        for (int i = 0; i < (int) Math.pow(2, N); i++) {
        }
        System.out.println(dp[(int) Math.pow(2, N) - 1]);
    }
}