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
        if (n == 1 && m == 1) {
            System.out.println(1);
            return;
        }

        if (n == 1) {
            System.out.println(m - 2);
            return;
        }

        if (m == 1) {
            System.out.println(n - 2);
            return;
        }

        System.out.println((n - 2) * (m - 2));
    }
}