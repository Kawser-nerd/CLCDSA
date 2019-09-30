import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    private static final int ALL_DIGITS_SAME = 111;

    public static String process(TestCase testCase) {
        final int N = testCase.N;

        return String.valueOf(
                IntStream.range(1, 10)
                .map(i -> i * ALL_DIGITS_SAME)
                .filter(contestNum -> contestNum >= N)
                .findFirst()
                .orElseThrow(() -> new IllegalArgumentException("N is too large: " + N))
        );
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

        return new TestCase(N);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;

        public TestCase(int N) {
            this.N = N;
        }
    }
}