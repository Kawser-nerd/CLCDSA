import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            new Main().solve(in);
        }
    }

    private void solve(Scanner in) {
        int H = in.nextInt(), W = in.nextInt();
        char[][] a = new char[H][W];
        for (int i = 0; i < H; i++) {
            a[i] = in.next().toCharArray();
        }
        char[][] r = new char[H][W];
        char[][] b = new char[H][W];
        // initialize
        for (int i = 0; i < H; i++) {
            Arrays.fill(r[i], DOT);
            Arrays.fill(b[i], DOT);
            r[i][0] = SHA;
            b[i][W - 1] = SHA;
            for (int j = 1; j < W - 1; j++) {
                r[i][j] = (i % 2 == 0) ? SHA : DOT;
                b[i][j] = (i % 2 == 1) ? SHA : DOT;
            }
        }
        // draw
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (a[i][j] == SHA) {
                    r[i][j] = SHA;
                    b[i][j] = SHA;
                }
            }
        }
        show(r);
        System.out.println();
        show(b);
    }

    private static final char DOT = '.', SHA = '#';

    private void show(char[][] cs) {
        for (int i = 0; i < cs.length; i++) {
            System.out.println(new String(cs[i]));
        }
    }
}