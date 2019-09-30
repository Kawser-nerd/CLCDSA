import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int p[] = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }

        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (p[i] == i + 1) {
                cnt++;
                p[i] = p[i + 1];
                p[i + 1] = i + 1;
            }
        }

        if (p[n - 1] == n) {
            cnt++;
        }

        System.out.println(cnt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}