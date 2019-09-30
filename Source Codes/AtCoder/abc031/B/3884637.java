import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();
        int H = sc.nextInt();
        int N = sc.nextInt();
        int A[] = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        for (int i = 0; i < N; i++) {
            if (A[i] < L) {
                System.out.println(L - A[i]);
            } else if (A[i] >= L && A[i] <= H) {
                System.out.println(0);
            } else {
                System.out.println(-1);
            }
        }

    }
}