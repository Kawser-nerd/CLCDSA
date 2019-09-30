import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            h[i] = sc.nextInt();
        }

        Arrays.sort(h);
        int min = h[0];
        int max = h[K-1];
        int diff = max - min;

        for (int i = K; i < N; i++) {
            min = h[i-K+1];
            max = h[i];
            diff = Math.min(diff, max - min);
        }

        out.println(diff);
    }
}