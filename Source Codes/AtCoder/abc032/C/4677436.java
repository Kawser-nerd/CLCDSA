import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();

        long[] s = new long[N];
        for (int i = 0; i < N; i++) {
            s[i] = sc.nextInt();
            if (s[i] == 0) {
                out.println(N);
                return;
            }
        }

        int maxLength = 0;
        long prod = 1;
        int l = 0;
        int r = 0;
        // ????
        while (l < N) {
            // ?????????????
            while (r < N && prod * s[r] <= K) {
                prod *= s[r++];
            }
            maxLength = Math.max(maxLength, r - l);

            // ??????
            if (l == r) {
                l++;
                r++;
                prod = 1;
            } else {
                prod /= s[l++];
            }
        }

        out.println(maxLength);
    }
}