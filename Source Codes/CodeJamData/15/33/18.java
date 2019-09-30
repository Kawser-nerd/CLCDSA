import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Piotr Zielinski on 5/10/15.
 */
public final class C {
    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            System.out.println(String.format("Case #%d: %d", i+1, testcase(sc)));
        }
    }

    private static int testcase(final Scanner sc) {
        final int c = sc.nextInt();
        final int d = sc.nextInt();
        final long v = sc.nextLong();

        final List<Integer> existing = new ArrayList<>();
        for (int i = 0; i < d; ++i) {
            final int n = sc.nextInt();
            existing.add(n);
        }

        int index = 0;
        int extraTypes = 0;
        long currentResult = 0;
        while (currentResult < v) {
            if (index == existing.size() || existing.get(index)-1 > currentResult) {
                ++extraTypes;
                currentResult += (currentResult + 1) * (long) c;
            } else {
                currentResult += existing.get(index) * (long) c;
                ++index;
            }
        }
        return extraTypes;
    }

}
