import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        //???
        int[] cum = new int[N+1];

        for(int i = 0; i <= N - K; i++){
            cum[i]++;
            cum[i+K]--;
        }

        for(int i = 1; i <= N; i++) {
            cum[i] += cum[i-1];
        }

        long ans = 0;
        for(int i = 0; i < N; i++) {
            ans += (long)a[i] * cum[i];
        }

        out.println(ans);
    }
}