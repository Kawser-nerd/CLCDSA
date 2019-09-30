import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] X = new int[M];
        for (int i = 0; i < M; i++) {
            X[i] = sc.nextInt();
        }

        Arrays.sort(X);

        int[] xDiff = new int[M - 1];
        for (int i = 0; i < M - 1; i++) {
            xDiff[i] = Math.abs(X[i] - X[i+1]);
        }

        Arrays.sort(xDiff);
        int ans = 0;
        for (int i = 0; i < M - N; i++) {
            ans += xDiff[i];
        }

        out.println(ans);
    }
}