import java.util.Scanner;

public class Main {
    public void main(Scanner sc) {
        long n = sc.nextLong();
        long m = sc.nextLong();

        System.out.println(calc(n, m));
    }

    private long calc(long n, long m) {
        if (n == 2 || m == 2) {
            return 0;
        }

        if (n > m) {
            long tmp = n;
            n = m;
            m = tmp;
        }

        if (n == 1) {
            return (m == 1) ? 1 : m - 2;
        }

        return (n - 2) * (m - 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}