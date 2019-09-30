import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long Q = sc.nextLong();
        long H = sc.nextLong();
        long S = sc.nextLong();
        long D = sc.nextLong();
        long N = sc.nextLong();

        long onePrice = Math.min(Math.min(Q * 4, H * 2), S);

        if ((double) onePrice <= (double) D / 2) {
            out.println(N * onePrice);
        } else {
            out.println((N / 2) * D + (N % 2) * onePrice);
        }
    }
}