import java.util.*;

import static java.lang.System.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        long A = nl();
        long B = nl();
        long C = nl();

        if (A + B >= C) {
            out.println(B + C);
        } else {
            // at last, eat a poisoned cookie
            out.println(B + (A + B) + 1);
        }
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