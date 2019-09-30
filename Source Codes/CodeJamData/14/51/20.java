package Round3;

import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int _ = 1; _ <= t; _++) {
            int n = in.nextInt();
            int p = in.nextInt();
            int q = in.nextInt();
            int r = in.nextInt();
            int s = in.nextInt();
            int[] A = new int[n];
            long[] S = new long[n + 1];
            for (int i = 0; i < n; i++) {
                A[i] = (int) (((long) i * p + q) % r + s);
                S[i + 1] = S[i] + A[i];
            }
            long max = 0;
            for (int i = 0; i < n; i++) {
                int lo = 0;
                int hi = i;
                int ans = -1;
                long tot = S[i + 1] - S[0];
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    long center = S[i + 1] - S[mid];
                    long left = tot - center;
                    // System.out.println(mid + " " + left + " " + center);
                    if (left > center) {
                        hi = mid - 1;
                    } else {
                        ans = mid;
                        lo = mid + 1;
                    }
                }
                // System.out.println(i + " " + ans);
                long diff1 = Math.abs(S[i + 1] - S[ans] - (S[ans] - S[0]));
                long diff2 = Math.abs(S[i + 1] - S[ans + 1]
                        - (S[ans + 1] - S[0]));
                if (diff2 < diff1)
                    ans++;
                // System.out.println(i + " " + ans + " " + diff1 + " " +
                // diff2);
                long center = S[i + 1] - S[ans];
                long left = S[ans] - S[0];
                long right = S[n] - left - center;
                long take = S[n] - Math.max(center, Math.max(left, right));
                max = Math.max(max, take);
            }
            System.out.println("Case #" + _ + ": " + (max * 1.0 / S[n]));
        }
    }
}
