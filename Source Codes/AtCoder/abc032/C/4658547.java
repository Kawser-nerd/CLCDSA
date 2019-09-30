import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);


    public static void main(String[] args) {
        int n = sc.nextInt();
        long k = sc.nextLong();
        long[] values = new long[n];

        for (int i = 0; i < n; i++) {
            values[i] = sc.nextLong();
            if (values[i] == 0) {
                System.out.println(n);
                return;
            }
        }

        int l = 0, r = 0, res = 0;
        long prod = 1;
        while (l < n) {
            while (r < n && prod * values[r] <= k) prod *= values[r++];
            res = Math.max(res, r - l);
            if (l == r) prod *= values[r++];
            prod /= values[l++];
        }

        System.out.println(res);
    }
}