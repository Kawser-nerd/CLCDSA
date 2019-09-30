import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static String process(TestCase testCase) {
        final int N = testCase.N;
        final int X = testCase.X;
        final List<Integer> x = testCase.x;

        final int num = x.stream()
                .map(xi -> Math.abs(X - xi))
                .reduce(Main::gcd)
                .orElseThrow(() -> new IllegalArgumentException("x is empty"));
        return String.valueOf(num);
    }

    private static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final String result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int X = sc.nextInt();
        final List<Integer> x = IntStream.range(0, N).mapToObj(i -> sc.nextInt()).collect(Collectors.toList());

        return new TestCase(N, X, x);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final int X;
        final List<Integer> x;

        public TestCase(int N, int X, List<Integer> x) {
            this.N = N;
            this.X = X;
            this.x = x;
        }
    }
}