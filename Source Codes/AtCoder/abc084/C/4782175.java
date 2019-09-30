import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] C = new int[N];
        int[] S = new int[N];
        int[] F = new int[N];
        for (int i = 0; i < N - 1; i++) {
            C[i] = sc.nextInt();
            S[i] = sc.nextInt();
            F[i] = sc.nextInt();
        }

        for (int i = 0; i < N; i++) {
            int time = 0;
            for (int j = i; j < N - 1; j++) {
                int start = S[j];
                if (time > S[j]) {
                    if ((time - S[j]) % F[j] != 0) {
                        start = S[j] + (((time - S[j]) / F[j]) + 1) * F[j];
                    } else {
                        start = time;
                    }
                }

                int wait = start - time;
                time += wait + C[j];
            }
            out.println(time);
        }
    }
}