import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int x = sc.nextInt();
        int ans = 0;
        for (int i = 0; ; i++) {
            ans += i;
            if (ans >= x) {
                System.out.println(i);
                break;
            }
        }
    }
}