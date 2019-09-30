import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        int M = sc.nextInt();
        int X = sc.nextInt();
        int Y = sc.nextInt();

        int[] xs = new int[N];
        int maxX = -100;
        for (int i = 0; i < N; i++) {
            xs[i] = sc.nextInt();
            maxX = Math.max(xs[i], maxX);
        }

        int[] ys = new int[M];
        int minY = 100;
        for (int i = 0; i < M; i++) {
            ys[i] = sc.nextInt();
            minY = Math.min(ys[i], minY);
        }

        if (Y <= X) {
            System.out.println("War");
            return;
        }

        for (int i = X + 1; i <= Y; i++) {
            if ((maxX < i) && (minY >= i)) {
                System.out.println("No War");
                return;
            }
        }
        System.out.println("War");

    }
}