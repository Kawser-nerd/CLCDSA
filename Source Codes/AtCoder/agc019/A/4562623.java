import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        int h = sc.nextInt();
        int s = sc.nextInt();
        int d = sc.nextInt();
        int n = sc.nextInt();
        q *= 4;
        h *= 2;

        sc.close();

        int min = Math.min(q, Math.min(h, s));

        if (n % 2 == 0) {
            System.out.println(Math.min((long) min * n, (long) d * n / 2));
        } else {
            System.out.println(Math.min((long) min * n, (long) d * (n - 1) / 2 + min));
        }

    }

}