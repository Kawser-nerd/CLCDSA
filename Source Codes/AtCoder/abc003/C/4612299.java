import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int[] R = new int[N];
        for (int i = 0; i < N; i++) {
            R[i] = sc.nextInt();
        }

        Arrays.sort(R);
        double ans = 0.0;
        for (int i = N - K; i < N; i++) {
            ans = (ans + R[i]) / 2.0;
        }
        out.println(ans);
    }
}