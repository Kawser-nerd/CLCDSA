import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in);) {
            new Main().solve(sc);
        }
    }

    void solve(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        System.out.println((1900 * m + 100 * (n - m)) * (int)Math.pow(2, m));
    }
}