import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        long ret = 0;

        if (A[0] > 0) {
            System.out.println(-1);
            return;
        }

        int prevA = 0;
        for (int i = 1; i < N; i++) {
            if (A[i] > prevA + 1) {
                System.out.println(-1);
                return;
            } else if (A[i] == prevA + 1) {
                ret++;
            } else {
                ret += A[i];
            }

            prevA = A[i];
        }

        System.out.println(ret);
    }
}