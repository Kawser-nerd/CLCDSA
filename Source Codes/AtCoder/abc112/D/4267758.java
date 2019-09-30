import java.util.Scanner;

public class Main {
    public void main(Scanner sc) throws Exception {
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.close();

        int ans = 1;
        for (int i = 1; i * i <= m; i++) {
            if (m % i != 0) {
                continue;
            }

            if (i >= n) {
                ans = Math.max(ans, m / i);
            } else if (m / i >= n) {
                ans = Math.max(ans, i);
            }
        }

        System.out.println(ans);
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
    }
}