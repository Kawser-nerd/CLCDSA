import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int K = sc.nextInt();
        boolean[] A = new boolean[10];
        for(int i = 0; i < K; ++i) {
            int D = sc.nextInt();
            A[D] = true;
        }

        for(int i = N; ; ++i) {
            if (check(i, A, K)) {
                System.out.println(i);
                return;
            }
        }
    }

    static boolean check(int N, boolean[] A, int K) {
        while(N > 0) {
            if (A[N % 10]) {
                return false;
            }
            N /= 10;
        }
        return true;
    }
}