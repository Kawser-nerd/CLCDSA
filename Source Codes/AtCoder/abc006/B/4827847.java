import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        final int MOD = 10007;

        Scanner sc = new Scanner(System.in);
        int[] a = new int[1000001];
        a[1] = a[2] = 0;
        a[3] = 1;

        int n = sc.nextInt();

        for (int i = 4; i <= n; i++) {
            a[i] = (a[i-3] + a[i-2] + a[i-1]) % MOD;
        }

        System.out.println(a[n]);
    }
}