import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        long x = sc.nextLong();
        long ans = 2 * (x / 11);
        long remain = x % 11;
        if (remain == 0) {
            System.out.println(ans);
        } else if (remain <= 6) {
            System.out.println(ans + 1l);
        } else {
            System.out.println(ans + 2l);
        }
    }
}