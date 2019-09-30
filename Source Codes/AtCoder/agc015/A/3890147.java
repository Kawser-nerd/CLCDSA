import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        long n = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        
        if (b < a) {
            System.out.println(0);
            return;
        }

        if (n == 1 && a != b) {
            System.out.println(0);
            return;
        } else if (n == 1) {
            System.out.println(1);
            return;
        }

        System.out.println((n - 2) * (b - a) + 1);
    }
}