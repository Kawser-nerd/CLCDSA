import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double n = sc.nextDouble();
        double m = sc.nextDouble();
        double x = 30.0000 * (n % 12) + 0.5000 * m;
        double y = 6.0000 * m;
        double ans = Math.abs(x - y);
        if (ans > 180) {
            ans = 360 - ans;
        }
        System.out.printf("%.4f%n", ans);
    }
}