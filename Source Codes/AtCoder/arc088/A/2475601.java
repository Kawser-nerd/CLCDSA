import java.util.Scanner;

public class Main {
    public void main(Scanner sc) {
        long x = sc.nextLong();
        long y = sc.nextLong();

        int cnt = 0;
        for (; x <= y; cnt++) {
            x *= 2;
        }

        System.out.println(cnt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}