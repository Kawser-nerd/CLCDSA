import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int h = sc.nextInt();
        int w = sc.nextInt();
        int n = sc.nextInt();
        int p = 0;
        String all[] = new String[h * w];
        for (int i = 1; i <= n; i++) {
            int a = sc.nextInt();
            for (int j = 0; j < a; j++) {
                all[p++] = "" + i;
            }
        }

        p = 0;
        for (int i = 0; i < h; i++) {
            String c[] = new String[w];
            if (i % 2 == 0) {
                for (int j = 0; j < w; j++) {
                    c[j] = all[p++];
                }
            } else {
                for (int j = w - 1; j >= 0; j--) {
                    c[j] = all[p++];
                }
            }

            System.out.println(String.join(" ", c));
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}