import java.util.*;

class Main {
        public static void main(String args[]) {
                try (Scanner sc = new Scanner(System.in)) {
                        int N = sc.nextInt();
                        long[] A = new long[N];
                        long[] B = new long[N];
                        for (int i = 0; i < N; i++) {
                                A[i] = i * 10001L + 1;
                                B[N-i-1] = i * 10001L + 1;
                        }
                        for (int i = 0; i < N; i++) {
                                int p = sc.nextInt();
                                p--;
                                A[p] += i / 2;
                                B[p] += i - i / 2;
                        }
                        for (int i = 0; i < N; i++) {
                                System.out.print(A[i]);
                                if (i == N - 1) {
                                        System.out.print("\n");
                                } else {
                                        System.out.print(" ");
                                }
                        }
                        for (int i = 0; i < N; i++) {
                                System.out.print(B[i]);
                                if (i == N - 1) {
                                        System.out.print("\n");
                                } else {
                                        System.out.print(" ");
                                }
                        }
                }
        }
}