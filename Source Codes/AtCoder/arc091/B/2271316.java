import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        long count = 0L;
        if (k == 0) {
            count = (long)n*n;
            System.out.println(count);
        } else {
            for (int y = k + 1; y <= n; y++) {
                count += (long)(n / y) * (y - k);
                if (n % y >= k) {
                    count +=(long) n % y - k + 1;
                }
            }
            System.out.println(count);
        }
    }
}