import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] A = new long[N];
        long ans = 1;
        boolean f = true;
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextLong();
        }
        lavel:
        for (int i = 1; i < N; i++) {
            if (A[i - 1] < A[i]) {
                f = true;
            } else if (A[i - 1] > A[i]) {
                f = false;
            }
            if (A[i - 1] == A[i]) {
                continue;
            }
            for (int j = i + 1; j < N; j++) {
                if ((f == false) && A[j - 1] < A[j]) {
                    ans++;
                    i = j;
                    break;
                } else if ((f == true) && A[j - 1] > A[j]) {
                    ans++;
                    i = j;
                    break;
                }
                if (A[j - 1] == A[j]) {
                    continue;
                }
                if (j == N - 1) {
                    break lavel;
                }
            }
        }
        System.out.println(ans);
    }
}