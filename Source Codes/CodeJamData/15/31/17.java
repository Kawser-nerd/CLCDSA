import java.util.Scanner;

/**
 * Created by Piotr Zielinski on 5/10/15.
 */
public final class A {
    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            System.out.println(String.format("Case #%d: %d", i+1, testcase(sc)));
        }
    }

    private static int testcase(final Scanner sc) {
        final int r = sc.nextInt();
        final int c = sc.nextInt();
        final int w = sc.nextInt();

        return (c / w) * r + (w - 1) + (c % w == 0 ? 0 : 1);
    }
}
