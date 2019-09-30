import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import static java.util.stream.Collectors.toList;

public class Main{
    private static final BigDecimal CONVERSION = new BigDecimal("0.006");

    public static int process(TestCase testCase) {
        int N = testCase.N;
        int T = testCase.T;
        int A = testCase.A;
        List<Integer> H = testCase.H;

        final List<BigDecimal> diffs = H.stream().map(x -> asTemperature(x, T)).map(t -> asDiff(t, A)).collect(toList());

        int minIndex = 0;
        for (int i = 1, length = H.size(); i < length; ++i) {
            final BigDecimal minDiff = diffs.get(minIndex);
            final BigDecimal diff = diffs.get(i);
            final boolean isCloser = diff.compareTo(minDiff) < 0;
            if (isCloser) {
                minIndex = i;
            }
        }

        return minIndex + 1;
    }

    private static BigDecimal asTemperature(int x, int t) {
        return BigDecimal.valueOf(t).subtract(CONVERSION.multiply(BigDecimal.valueOf(x)));
    }

    private static BigDecimal asDiff(BigDecimal t, int a) {
        return t.subtract(BigDecimal.valueOf(a)).abs();
    }

    private static boolean is753(int x) {
        return x == 7 || x == 5 || x == 3;
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final int result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int T = sc.nextInt();
        int A = sc.nextInt();

        List<Integer> H = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            H.add(sc.nextInt());
        }

        sc.close();
        return new TestCase(N, T, A, H);
    }

    private static void output(int result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final int T;
        final int A;
        final List<Integer> H;

        public TestCase(int N, int T, int A, List<Integer> H) {
            this.N = N;
            this.T = T;
            this.A = A;
            this.H = H;
        }
    }
}