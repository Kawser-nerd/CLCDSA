import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            max = Math.max(a[i], max);
        }
        if (n == 1) {
            if (a[0] == k) {
                System.out.println("POSSIBLE");
                return;
            } else {
                System.out.println("IMPOSSIBLE");
                return;
            }
        }

        int [] b = new int[n];
        int c = gcd(a[0], a[1]);
        b[0] = c;
        for (int i = 1 ; i < n ; i++) {
            b[i] = gcd(b[i - 1], a[i]);
        }

        if (k % b[n - 1] == 0 && k <= max) {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }

    }

    private static int gcd(int m, int n) {
        if(m < n) return gcd(n, m);
        if(n == 0) return m;
        return gcd(n, m % n);
    }

}