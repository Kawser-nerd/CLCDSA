import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int ans = Integer.MAX_VALUE;
        if (x <= y) {
            ans = Math.min(ans, Math.abs(x - y));
        }
        if (-1 * x <= y) {
            ans = Math.min(ans, Math.abs(-1 * x - y) + 1);
        }
        if (x <= -y) {
            ans = Math.min(ans, Math.abs(x + y) + 1);
        }
        if (-1 * x <= -1 * y) {
            ans = Math.min(ans, Math.abs(y - x) + 2);
        }
        System.out.println(ans);
        return;
    }
}