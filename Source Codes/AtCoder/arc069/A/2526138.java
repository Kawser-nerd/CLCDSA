import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNextLong()) {
            long n = sc.nextLong();
            long m = sc.nextLong();

            long ans = Math.min(n, m / 2);

            m -= ans * 2;

            if (m > 0) {
                ans += m / 4;
            }

            System.out.println(ans);
        }
    }
}