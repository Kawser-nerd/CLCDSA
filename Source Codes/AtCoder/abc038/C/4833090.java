import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        long total = 0;
        long subtotal = 1;
        int pre = a[0];
        for (int i = 1; i < N; i++) {
            if (pre >= a[i]) {
                total += subtotal;
                if (subtotal > 1) {
                    total += subtotal * (subtotal - 1) / 2;
                }
                subtotal = 1;
            } else {
                subtotal++;
            }
            pre = a[i];
        }

        total += subtotal;
        if (subtotal > 1) {
            total += subtotal * (subtotal - 1) / 2;
        }
        out.println(total);
    }
}