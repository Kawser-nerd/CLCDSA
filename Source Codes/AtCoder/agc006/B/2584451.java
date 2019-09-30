import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int x = sc.nextInt();
        int nn = 2 * n - 1;

        if (x == 1 || x == nn) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
            for (int i = 0; i < nn; i++) {
                System.out.println((i + x + n - 1) % nn + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}