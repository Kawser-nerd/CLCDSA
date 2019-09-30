import java.util.Scanner;

class C {
    public static void main(String...args) {
        final Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt();
        final int[] x = new int[N + 1];
        final int[] y = new int[N + 1];
        final int[] t = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            t[i] = sc.nextInt();
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        for(int i = 1; i <= N; i++) {
            final int dist = Math.abs(x[i] - x[i - 1]) + Math.abs(y[i] - y[i - 1]);
            if(dist > t[i] - t[i - 1] || (dist - t[i] + t[i - 1]) % 2 != 0) {
                System.err.println(dist + " " + i);
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
public class Main {
    public static void main(String... args) {
        C.main(args);
    }
}