import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int gcd = a[0];
        for (int i = 0; i < n; i++) {
            gcd = gcd(gcd, a[i]);
        }
        Arrays.sort(a);
        if (k <= a[n - 1] && k % gcd == 0) {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}