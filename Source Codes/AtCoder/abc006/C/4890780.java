import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), m = scanner.nextInt();
        int a2 = 0, a3 = 0, a4 = 0;
        if (m % 2 == 1) {
            a3++;
            m -= 3;
            n--;
        } if (m % 4 == 2) {
            a2++;
            m -= 2;
            n--;
        }

        if (2 * n > m || m > 4 * n) {
            System.out.println("-1 -1 -1");
        } else {
            a2 += (4 * n - m) / 2;
            a4 += (m - (4 * n - m)) / 4;
            System.out.println(a2 + " " + a3 + " " + a4);
        }
    }
}