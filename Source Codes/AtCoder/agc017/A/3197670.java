import java.util.*;

public class Main {

    int INF = Integer.MAX_VALUE;
    int N;
    int[] A;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        int P = sc.nextInt();
        A = new int[N];
        boolean c = true;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            if (A[i] % 2 == 1) {
                c = false;
            }
        }
        if (P == 0) {
            System.out.println(c ? (long) Math.pow(2, N) : (long) Math.pow(2, N - 1));
        } else {
            System.out.println(c ? "0" : (long)Math.pow(2, N - 1));
        }

    }
}