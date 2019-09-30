import java.util.Scanner;

public class Main {
    static Scanner in;

    void solve() {
        int h = in.nextInt(), w = in.nextInt();
        if (h * w == 1) {
            System.out.println(0);
            return;
        }
        if (h == 1) {
            System.out.println(w - 1);
            return;
        }
        if (w == 1) {
            System.out.println(h - 1);
            return;
        }
        System.out.println(((h-1)*w + h*(w-1)));
    }

    public static void main(String[] args) {
        in = new Scanner(System.in);
        new Main().solve();
    }
}