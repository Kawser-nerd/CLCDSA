import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int A = sc.nextInt();
        int B = sc.nextInt();
        int Q = sc.nextInt();

        long[] s = new long[A];
        long[] t = new long[B];

        for (int i = 0; i < A; i++) {
            s[i] = sc.nextLong();
        }
        for (int i = 0; i < B; i++) {
            t[i] = sc.nextLong();
        }

//        System.out.println(Arrays.toString(s));
//        System.out.println(Arrays.toString(t));

        for (int i = 0; i < Q; i++) {
            long x = sc.nextLong();
//            System.out.println(x);

            int sPosi = ~Arrays.binarySearch(s, x);
//            System.out.println(sPosi);
            int tPosi = ~Arrays.binarySearch(t, x);
//            System.out.println(tPosi);


            long s1 = -1;
            long t1 = -1;
            long s2 = -1;
            long t2 = -1;

            if (0 < sPosi) {
                s1 = s[sPosi-1];
            }
            if (sPosi < A) {
                s2 = s[sPosi];
            }

            if (0 < tPosi) {
                t1 = t[tPosi-1];
            }
            if (tPosi < B) {
                t2 = t[tPosi];
            }

//            System.out.println("---");
//            System.out.println(s1);
//            System.out.println(s2);
//            System.out.println("---");
//            System.out.println(t1);
//            System.out.println(t2);
//            System.out.println("---");

            long ans = Long.MAX_VALUE;
            long d = 0;
            if (s1 > 0 && t1 > 0) {
                d = Math.max(Math.abs(x - s1), Math.abs(x - t1));
//                System.out.println("a " + d);
                ans = Math.min(ans, d);
            }
            if (s2 > 0 && t2 > 0) {
                d = Math.max(Math.abs(x - s2), Math.abs(x - t2));
//                System.out.println("b " + d);
                ans = Math.min(ans, d);
            }
            if (t1 > 0 && s2 > 0) {
                d = Math.min(Math.abs(x - t1), Math.abs(x - s2)) + Math.abs(t1 - s2);
//                System.out.println("c " + d);
                ans = Math.min(ans, d);
            }
            if (t2 > 0 && s1 > 0) {
                d = Math.min(Math.abs(x - t2), Math.abs(x - s1)) + Math.abs(t2 - s1);
//                System.out.println("d " + d);
//                System.out.println("x - t2 " + (x - t2));
//                System.out.println("t2 - s1 " + (t2 - s1));
                ans = Math.min(ans, d);
            }

            System.out.println(ans);
//            System.out.println("======================");
        }
    }
}