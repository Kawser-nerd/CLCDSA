import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        double xa = scanner.nextInt(), ya = scanner.nextInt(), xb = scanner.nextInt(), yb = scanner.nextInt(), xc = scanner.nextInt(), yc = scanner.nextInt();
        System.out.println(Math.abs((xb - xa) * (yc - ya) - (yb - ya) * (xc - xa)) / 2);
    }
}