import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[3 * n];
        for (int i = 0 ; i < 3 * n ; i++) {
            a[i] = sc.nextLong();
        }

        Arrays.sort(a);

        long ans = 0;
        for (int i = 0 ; i < 2 * n ; i++) {
            if (i % 2 == 0) {
                ans += a[i + n];
            }
        }

        System.out.println(ans);
    }

}