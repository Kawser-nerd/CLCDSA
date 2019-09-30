import java.util.*;

import static java.lang.System.*;

// 2?????
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int Q = sc.nextInt();

        int[][] sum = new int[N+1][N+1];
        for(int i = 0; i < M; i++){
            sum[sc.nextInt()][sc.nextInt()]++;
        }

        int[] p = new int[Q];
        int[] q = new int[Q];
        for(int i = 0; i < Q; i++){
            p[i] = sc.nextInt();
            q[i] = sc.nextInt();
        }

        for(int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++){
                sum[i][j] += sum[i-1][j];
                sum[i][j] += sum[i][j-1];
                sum[i][j] -= sum[i-1][j-1];
            }
        }

        for(int i = 0; i < Q; i++){
            out.println(sum[q[i]][q[i]] - sum[p[i]-1][q[i]] - sum[q[i]][p[i]-1] + sum[p[i]-1][p[i]-1]);
        }

    }
}