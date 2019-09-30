import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int Q = sc.nextInt();

        int[][] table = new int[N+1][N+1];

        for (int i = 0; i < M; i++) {
            table[sc.nextInt()][sc.nextInt()]++;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < N; j++) {
                table[i][j+1] += table[i][j];
            }
        }

        for (int i = 0; i < Q; i++) {
            int p = sc.nextInt();
            int q = sc.nextInt();

            int sum = 0;

            for (int j = p; j <= q; j++) {
                sum += table[j][q] - table[j][p-1];
            }

            System.out.println(sum);
        }
    }
}