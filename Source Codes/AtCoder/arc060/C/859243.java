import java.util.*;

class Main {
        private static int[][] c;
        public static void main(String args[]) {
                Scanner sc = new Scanner(System.in);
                int N = sc.nextInt();
                int[] x = new int[N];
                for (int i = 0; i < N; i++) {
                        x[i] = sc.nextInt();
                }
                c = new int[20][N];
                int L = sc.nextInt(), Q = sc.nextInt();
                int idx = 0;
                while (idx < N && x[idx] - x[0] <= L) {
                        idx++;
                }
                if (idx == N) {
                        for (int i = 0; i < Q; i++) {
                                System.out.println(1);
                        }
                        return;
                }
                c[0][0] = idx - 1;
                for (int i = 1; i < N; i++) {
                        while (idx < N && x[idx] - x[i] <= L) {
                                idx++;
                        }
                        if (idx == N) {
                                while (i < N) {
                                        c[0][i] = N - 1;
                                        i++;
                                }
                        } else {
                                c[0][i] = idx - 1;
                        }
                }
                for (int i = 1; i < 20; i++) {
                        for (int j = 0; j < N; j++) {
                                c[i][j] = c[i-1][c[i-1][j]];
                        }
                }
                for (int i = 0; i < Q; i++) {
                        int A = sc.nextInt() - 1, B = sc.nextInt() - 1;
                        if (A > B) {
                                int C = A;
                                A = B;
                                B = C;
                        }
                        System.out.println(calc(A,B));
                }
        }
        public static int calc(int A, int B) {
                int idx = 0;
                while (c[idx][A] < B) {
                        idx++;
                }
                if (idx == 0) {
                        return 1;
                } else {
                        return (1 << (idx - 1)) + calc(c[idx - 1][A], B);
                }
        }
}