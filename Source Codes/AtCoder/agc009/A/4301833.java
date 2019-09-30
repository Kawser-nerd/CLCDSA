import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        long[] b = new long[n];
        for (int i = 0 ; i < n ; i++) {
            a[i] = sc.nextLong();
            b[i] = sc.nextLong();
        }

        long count = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            if ((a[i] + count) % b[i] != 0) {
                count += b[i] - ((a[i] + count) % b[i]);
            }

        }

        System.out.println(count);

    }

}