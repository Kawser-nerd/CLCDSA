import java.util.*;

import static java.lang.System.*;

public class Main {
    public static int A;
    public static int B;
    public static int C;


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        A = sc.nextInt();
        B = sc.nextInt();
        C = sc.nextInt();

        int[] l = new int[N];
        for (int i = 0; i < N; i++) {
            l[i] = sc.nextInt();
        }

        out.println(calMin(0, 0, 0, l, 0, 0));
    }

    public static int calMin(int a, int b, int c, int[] l, int i, int cost) {
        if (i == l.length) {
            if (a == 0 || b == 0 || c == 0) {
                return Integer.MAX_VALUE;
            } else {
                return cost + Math.abs(A - a) + Math.abs(B - b) + Math.abs(C - c) - 30;
            }
        }

        return Math.min(
                Math.min(
                        calMin(a + l[i], b, c, l, i + 1, cost + 10),
                        calMin(a, b + l[i], c, l, i + 1, cost + 10)
                ),
                Math.min(
                        calMin(a, b, c + l[i], l, i + 1, cost + 10),
                        calMin(a, b, c, l, i + 1, cost)
                )
        );
    }
}