import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        long[] s = new long[n];
        for(int i = 0 ; i < n ; i++) {
            s[i] = sc.nextLong();
        }
        for(int i = 0 ; i < n ; i++) {
            if (s[i] == 0) {
                System.out.println(n);
                return;
            }
        }
        int r = 0;
        int count = 0;
        long product = 1;
        for (int l = 0; l < n ; l++) {
            if (l > r) {
                r = l;
            }
            while(r < n && product * s[r] <= k) {
                product *= s[r];
                r++;
            }
            count = Math.max(r - l, count);
            if (product > 1) {
                product /= s[l];
            }
        }
        System.out.println(count);
    }

}