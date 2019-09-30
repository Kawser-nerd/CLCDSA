import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by Piotr Zielinski on 5/10/15.
 */
public final class B {
    public static void main(final String... args) {
        final Scanner sc = new Scanner(System.in);
        final int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            System.out.println(String.format("Case #%d: %.7f", i+1, testcase(sc)));
        }
    }

    private static double testcase(final Scanner sc) {
        final int k = sc.nextInt();
        final int l = sc.nextInt();
        final int s = sc.nextInt();

        final String keyboard = sc.next();
        final String text = sc.next();

        final int[] perm = new int[s];
        Arrays.fill(perm, 0);

        int maxOccurences = 0;
        double sum = 0.0;
        double denominator = 0;

        do {
            // build a new text from perm
            final StringBuilder builder = new StringBuilder(s);
            for (int i = 0; i < s; ++i) {
                builder.append(keyboard.charAt(perm[i]));
            }
            final String result = builder.toString();

            int howMany = 0;
            for (int i = 0; i < s-l+1; ++i) {
                if (result.substring(i, i+l).equals(text)) {
                    ++howMany;
                }
            }
            maxOccurences = Math.max(maxOccurences, howMany);
            sum += howMany;
            ++denominator;

        } while (nextPermutation(perm, k));

        return maxOccurences - (sum / denominator);
    }

    private static boolean nextPermutation(final int[] perm, final int k) {
        int i = 0;
        while (i < perm.length && perm[i] == k-1) {
            perm[i] = 0;
            ++i;
        }
        if (i == perm.length) {
            return false;
        }

        ++perm[i];
        return true;
    }
}
