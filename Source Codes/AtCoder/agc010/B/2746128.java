import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        int a[] = new int[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            sum += a[i];
        }

        long onetime = n;
        onetime *= n + 1;
        onetime /= 2;
        if (sum % onetime != 0) {
            end();
        }

        int times = (int) (sum / onetime);
        for (int i = 0; i < n; i++) {
            int d = a[(i + 1) % n] - a[i] - times;
            if (d > 0 || d % n != 0) {
                end();
            }
        }

        System.out.println("YES");
    }

    private void end() {
        System.out.println("NO");
        System.exit(0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}