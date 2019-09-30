import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] nm = scanner.nextLine().split(" ", 2);
        long n = Long.parseLong(nm[0]);
        long m = Long.parseLong(nm[1]);

        if (m > 4 * n) {
            System.out.println("-1 -1 -1");
        } else if (m >= 3 * n) {
            long rest = m - 3 * n;
            System.out.printf("0 %d %d\n", n - rest, rest);
        } else if (m >= 2 * n) {
            long rest = m - 2 * n;
            System.out.printf("%d %d 0\n", n - rest, rest);
        } else {
            System.out.println("-1 -1 -1");
        }
    }
}