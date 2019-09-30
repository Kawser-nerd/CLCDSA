import java.util.Scanner;

public class Main {
    static int cx, cy, r, sx1, sy1, sx2, sy2;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        cx = sc.nextInt();
        cy = sc.nextInt();
        r = sc.nextInt();
        sx1 = sc.nextInt();
        sy1 = sc.nextInt();
        sx2 = sc.nextInt();
        sy2 = sc.nextInt();
        boolean visibleCircle = !(inSquare(cx + r, cy) && inSquare(cx - r, cy) && inSquare(cx, cy + r) && inSquare(cx, cy - r));
        boolean visibleSquare = !(inCircle(sx1, sy1) && inCircle(sx2, sy1) && inCircle(sx1, sy2) && inCircle(sx2, sy2));

        System.out.println(visibleCircle ? "YES" : "NO");
        System.out.println(visibleSquare ? "YES" : "NO");
    }


    public static boolean inCircle(int x, int y) {
        int dx = cx - x;
        int dy = cy - y;
        return dx * dx + dy * dy <= r * r;
    }

    public static boolean inSquare(int x, int y) {
        return (sx1 <= x && x <= sx2) && (sy1 <= y && y <= sy2);
    }
}