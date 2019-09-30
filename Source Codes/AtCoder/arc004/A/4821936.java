import java.awt.Point;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Point[] p = new Point[n];
        for(int i = 0; i < n; i++) {
            p[i] = new Point(sc.nextInt(), sc.nextInt());
        }

        double ans = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                ans = Math.max(ans, p[i].distance(p[j]));
            }
        }
        System.out.println(ans);

        sc.close();
    }
}