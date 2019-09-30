import java.util.*;

public class Main {

    long INF = Long.MAX_VALUE;

    public static void main(String[] args) {
        new Main().solve();
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            System.out.println("Zero");
        } else if (b < 0) {
            long ans = (b - a) + 1;
            if (ans % 2 == 0) {
                System.out.println("Positive");
            } else {
                System.out.println("Negative");
            }
        } else {
            System.out.println("Positive");
        }
    }
}