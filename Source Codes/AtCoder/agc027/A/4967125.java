import java.util.*;

import static java.lang.System.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = ni();
        int x = ni();
        int[] a = niarr(N);

        Arrays.sort(a);

        int num = 0;
        int i = 0;
        while (i < N && x >= a[i]) {
            x -= a[i];
            i++;
            num++;
        }

        // give all but there is rest
        if (x > 0 && num > 0 && i == N) {
            num--;
        }

        out.println(num);
    }

    static int ni() {
        return sc.nextInt();
    }

    static long nl() {
        return sc.nextLong();
    }

    static String ns() {
        return sc.next();
    }

    static int[] niarr(int N) {
        int[] a = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }
        return a;
    }

    static long[] nlarr(int N) {
        long[] a = new long[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextLong();
        }
        return a;
    }
}