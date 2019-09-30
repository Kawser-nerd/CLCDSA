import java.util.*;

import static java.lang.System.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        long N = ni();
        long M = ni();
        String S = ns();
        String T = ns();

        long L = lcm(N, M);

        Map<Integer, Character> map = new HashMap<>();
        for (int i = 0; i < N; i++) {
            int index = (int)(L / N) * i + 1;
            map.put(index, S.charAt(i));
        }

        boolean flag = true;
        for (int i = 0; i < M; i++) {
            int index = (int)(L / M) * i + 1;

            if(map.containsKey(index) && T.charAt(i) != map.get(index)){
                flag = false;
                break;
            }
        }

        if(flag){
            out.println(L);

        } else {
            out.println(-1);
        }
    }

    //??: https://www.suzushin7.jp/entry/2016/11/05/calculate-least-common-multiple-in-java/
    //????? ?????????? O(logN)
    public static long gcd(long m, long n) {
        if (m < n) return gcd(n, m);
        if (n == 0) return m;
        return gcd(n, m % n);
    }

    //?????lcm ?????????? O(logN)
    public static long lcm(long m, long n) {
        return m * (n / gcd(m, n));  //m*n?long???????????????????????????
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