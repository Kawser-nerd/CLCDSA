import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    private enum Digit {
        NINE("9", "1"), ONE("1", "9");

        private final String from;
        private final String to;

        Digit(String from, String to) {
            this.from = from;
            this.to = to;
        }

        public static Digit fromString(String from) {
            return Arrays.stream(values())
                    .filter(digit -> digit.from.equals(from))
                    .findFirst()
                    .orElseThrow(() -> new IllegalArgumentException("Unknown digit: " + from));
        }

        public String convert() {
            return to;
        }
    }

    public static String process(TestCase testCase) {
        final int N = testCase.N;

        return Arrays.stream(String.valueOf(N).split(""))
                .map(Digit::fromString)
                .map(Digit::convert)
                .collect(Collectors.joining());
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