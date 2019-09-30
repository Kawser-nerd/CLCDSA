import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int t = sc.nextInt();
        long ans = 0;
        int preT = sc.nextInt();
        for (int i = 1; i < n; i++) {
            int ti = sc.nextInt();

            if (ti - preT >= t) {
                ans += t;
            } else {
                ans += ti - preT;
            }
            
            preT = ti;
        }
        System.out.println(ans + t);
    }
}