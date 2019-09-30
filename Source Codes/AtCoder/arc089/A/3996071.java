import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int currentT = 0;
        int currentX = 0;
        int currentY = 0;
        for (int i = 0; i < n; i++) {
            int t = sc.nextInt();
            int x = sc.nextInt();
            int y = sc.nextInt();

            int timeDistance = t - currentT;
            int manhattanDistance = Math.abs(x - currentX) + Math.abs(y - currentY);

            if (manhattanDistance > timeDistance || timeDistance % 2 == 0 && manhattanDistance % 2 == 1
                    || timeDistance % 2 == 1 && manhattanDistance % 2 == 0) {
                System.out.println("No");
                return;
            }

            currentT = t;
            currentX = x;
            currentY = y;
        }
        System.out.println("Yes");
    }
}