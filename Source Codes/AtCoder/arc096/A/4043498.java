import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();

        int ans = 5000 * 2 * 100000 + 1;
        int maxZ = 2 * Math.max(x, y);
        for (int i_z = 0; i_z <= maxZ; i_z++) {
            int i_x = Math.max(0, x - i_z / 2);
            int i_y = Math.max(0, y - i_z / 2);
            ans = Math.min(ans, a * i_x + b * i_y + c * i_z);
        }
        System.out.println(ans);
    }
}