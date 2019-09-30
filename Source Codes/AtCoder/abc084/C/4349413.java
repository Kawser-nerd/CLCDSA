import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] c = new int[n];
        int[] s = new int[n];
        int[] f = new int[n];
        for (int i = 1; i < n; i++) {
            c[i] = sc.nextInt();
            s[i] = sc.nextInt();
            f[i] = sc.nextInt();
        }
        long[] a = new long[n+1];
        for (int i = 1; i < n; i++) {
            long[] b = new long[n+1];
            for (int j = i+1; j <= n; j++) {
                if(b[j-1] <= s[j-1]) b[j] = s[j-1] + c[j-1];
                else if(b[j-1]%f[j-1] == 0) b[j] = b[j-1] + c[j-1];
                else b[j] = b[j-1] + (f[j-1] - (b[j-1]%f[j-1])) + c[j-1];
            }
            a[i] = b[n];
        }

        for (int i = 1; i <= n; i++) System.out.println(a[i]);
        sc.close();
    }

}