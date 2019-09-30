import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int x = sc.nextInt();
        int y = sc.nextInt();

        int xAbs = Math.abs(x);
        int yAbs = Math.abs(y);
        int ans = 0;
        if (x > 0 && xAbs >= yAbs || x < 0 && xAbs < yAbs) {
            ans++;
        }

        ans += Math.abs(xAbs - yAbs);

        if (y > 0 && xAbs >= yAbs || y < 0 && xAbs < yAbs) {
            ans++;
        }

        System.out.println(ans);
    }
}