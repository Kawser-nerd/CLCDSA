import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long x[] = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextLong();
        }

        long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans += Math.min(b, a * (x[i + 1] - x[i]));
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}