import java.util.Scanner;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long l = sc.nextLong();
        long[] ls = new long[n + 1];
        int sp = -1;
        for (int i = 1; i <= n; i++) {
            ls[i] = sc.nextLong();
            if (ls[i - 1] + ls[i] >= l) {
                sp = i;
            }
        }
        if (sp < 0) {
            System.out.println("Impossible");
        } else {
            System.out.println("Possible");
            for (int i = 1; i < sp - 1; i++) {
                System.out.println(i);
            }
            for (int i = n - 1; i >= sp - 1; i--) {
                System.out.println(i);
            }
        }
    }

    public static void main(String[] args) {
        new Main().run();
    }
}