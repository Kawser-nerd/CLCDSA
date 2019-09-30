import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] x = new int[N];
        int[] y = new int[N];
        int[] h = new int[N];
        for (int i = 0; i < N; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
            h[i] = sc.nextInt();
        }

        for (int cx = 0; cx <= 100; cx++) {
            for (int cy = 0; cy <= 100; cy++) {
                int H = 0;
                for (int i = 0; i < N; i++) {
                    if (h[i] != 0) {
                        H = h[i] + Math.abs(x[i] - cx) + Math.abs(y[i] - cy);
                        break;
                    }
                }

                boolean isAns = true;
                for (int i = 0; i < N; i++) {
                    int htmp = Math.max(H - Math.abs(x[i] - cx) - Math.abs(y[i] - cy), 0);
                    if (htmp != h[i]) {
                        isAns = false;
                        break;
                    }
                }

                if (isAns) {
                    out.println(cx + " " + cy + " " + H);
                    return;
                }
            }
        }
    }
}