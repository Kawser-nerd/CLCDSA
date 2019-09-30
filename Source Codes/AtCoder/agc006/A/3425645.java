import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();
        String T = sc.next();
        char[] s = S.toCharArray();
        char[] t = T.toCharArray();
        int ans = 2*N;
        lavel:
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - (i); j++) {
                if (s[i + j] != t[j]) {
                    continue lavel;
                }
                if (j == N - i - 1) {
                    System.out.println((N+i));
                    return;
                }
            }
        }
        System.out.println(ans);
    }
}