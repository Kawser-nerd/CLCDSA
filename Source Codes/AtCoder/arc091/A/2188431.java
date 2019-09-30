import java.util.Scanner;

public class Main {
    Main() {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long m = sc.nextInt();

        if (n > 1)
            n -= 2;

        if (m > 1)
            m -= 2;

        System.out.println(n * m);
    }

    public static void main (String[] args) {
        new Main();
    }

}