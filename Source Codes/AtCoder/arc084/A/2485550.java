import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);

        long[] bc = new long[n];
        {
            int j = 0;
            for (int i = 0; i < n; i++) {
                while (j < n && b[i] >= c[j]) {
                    j++;
                }
                bc[i] = n - j;
            }
        }
        long ret = 0;

        for (int i = n-1; i > 0; i--) {
            bc[i-1] += bc[i];
        }
        {
            int j = 0;
            for (int i = 0; i < n; i++) {
                while (j < n && a[i] >= b[j]) {
                    j++;
                }
                ret += j < n ?bc[j] : 0;
            }
        }
        System.out.println(ret);
    }
}