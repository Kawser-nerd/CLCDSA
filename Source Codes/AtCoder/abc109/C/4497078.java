import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int x = sc.nextInt();

        int[] ds = new int[N];
        for (int i = 0; i < N; i++) {
            ds[i] = Math.abs(sc.nextInt() - x);
        }

        int ans = ds[0];
        for (int i = 0; i < N; i++) {
            ans = gcd(ans, ds[i]);
        }

        System.out.println(ans);
    }


    static int gcd(int x, int y) {
        while (true) {
            int tmp = x % y;
            if (tmp == 0) {
                return y;
            }
            x = y;
            y = tmp;
        }
    }
}