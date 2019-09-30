import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        long n = sc.nextLong();
        long m = sc.nextLong();

        if (n * 2l <= m) {
            long ans = n;
            long remainC = m - n * 2l;
            ans += remainC / 4l;
            System.out.println(ans);
        } else {
            System.out.println(m / 2l);
        }
    }
}