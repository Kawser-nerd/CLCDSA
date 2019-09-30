import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int h = scanner.nextInt(), w = scanner.nextInt();
        System.out.println(h * (w - 1) + (h - 1) * w);
    }
}