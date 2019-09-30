import java.util.*;
import java.util.stream.Stream;

public class Main {

    private static int N;
    private static int A[][];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        A = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = sc.nextInt();
            }
        }
        System.out.println(solve());
    }

    static long solve() {

        boolean[][] indirect = new boolean[N][N];

        for (int i = 0; i < N-1 ; i++) {
            for (int j = i+1; j < N ; j++) {
                for (int k = 0; k < N; k++) {
                    if( k == i || k == j ) continue;
                    int ikj = A[i][k] + A[k][j];
                    int ij = A[i][j];
                    if( ikj < ij ) {
                        return -1;
                    } else if( ikj == ij ) {
                        indirect[i][j] = true;
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < N-1 ; i++) {
            for (int j = i+1; j < N ; j++) {
                if( !indirect[i][j] ) {
                    ans += A[i][j];
                }
            }
        }

        return ans;
    }
}