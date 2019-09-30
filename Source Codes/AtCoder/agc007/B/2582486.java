import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];

        int p[] = new int[n];
        for (int i = 0; i < n; i++) {
            p[sc.nextInt() - 1] = i + 1;
            a[i] = i * n + 1;
        }

        b[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            b[i] = b[i + 1] + n + p[i] - p[i + 1];
        }

        System.out.println(Arrays.toString(a).replaceAll("[^0-9 ]", ""));
        System.out.println(Arrays.toString(b).replaceAll("[^0-9 ]", ""));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}