import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();

        // ???
        int[] cum = new int[N + 2];
        for (int i = 0; i < Q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            cum[l] += 1;
            cum[r + 1] -= 1;
        }

        for (int n = 1; n < N + 2; n++) {
            cum[n] += cum[n - 1];
        }


        for (int n = 1; n <= N; n++) {
            if(cum[n] % 2 == 0) {
                out.print(0);
            } else {
                out.print(1);
            }
        }
        out.println();
    }
}