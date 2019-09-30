import java.util.Arrays;
import java.util.Scanner;

public class Main {

    void run() {
        Scanner sc = new Scanner(System.in);

        int[] x = new int[3];
        int[] y = new int[3];

        for (int i = 0; i < 3; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }

        for (int i = 2; i >= 0; i--) {
            x[i] -= x[0];
            y[i] -= y[0];
        }

        debug(x, y);

        System.out.println(area(x[1], y[1], x[2], y[2]));
    }

    double area(int x1, int y1, int x2, int y2) {
        return Math.abs(1.0 * x1 * y2 - 1.0 * x2 * y1) / 2;
    }

    void debug(Object...os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}