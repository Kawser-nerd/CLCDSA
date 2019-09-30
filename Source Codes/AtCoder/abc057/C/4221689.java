import java.util.Scanner;

public class Main {

    private static long largerDigit(long a, long b) {
        return Math.max(String.valueOf(a).length(), String.valueOf(b).length());
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long min = 0;
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i != 0) {
                continue;
            }
            long d = largerDigit(i, n / i);
            if (d < min || i == 1) {
                min = d;
            }
        }
        System.out.println(min);
    }

}