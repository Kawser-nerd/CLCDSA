import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            int ans = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                int cnt = 0;
                while (x % 2 == 0) {
                    x /= 2;
                    cnt++;
                }
                ans = Math.min(ans, cnt);
            }
            System.out.println(ans);
        }
    }
}