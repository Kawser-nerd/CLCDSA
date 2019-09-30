import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        long limit = sc.nextLong();
        long a[] = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        boolean ok = false;
        int ans[] = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            if (a[i] + a[i + 1] >= limit) {
                ans[i] = n - 1;
                ok = true;
                break;
            }
        }

        if (!ok) {
            System.out.println("Impossible");
            return;
        }

        int p = 1;
        for (int i = 0; ans[i] == 0; i++) {
            ans[i] = p++;
        }
        for (int i = n - 2; ans[i] == 0; i--) {
            ans[i] = p++;
        }

        System.out.println("Possible");
        for (int i = 0; i < n - 1; i++) {
            System.out.println(ans[i]);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}