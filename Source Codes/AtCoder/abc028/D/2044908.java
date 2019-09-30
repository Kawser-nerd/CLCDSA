import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        double n = (double)sc.nextInt();
        double k = (double)sc.nextInt();

        double ans = 6.0 * (k - 1) * (n - k) / n / n / n;
        ans += 3.0 * (n - 1) / n / n / n;
        ans += 1.0 / n / n / n;
        System.out.println(ans);
    }
}