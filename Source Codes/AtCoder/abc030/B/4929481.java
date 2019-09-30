import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        double a = 360.0 / 60 * m;
        double b = 360.0 / 12 * (n % 12) + a / 12;

        double ans = Math.abs(a - b);
        System.out.println(ans > 180 ? 360 - ans : ans);
    }
}