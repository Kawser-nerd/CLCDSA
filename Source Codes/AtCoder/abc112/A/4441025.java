import java.util.Optional;
import java.util.Scanner;

public class Main {

    private static final String HELLO_WORLD = "Hello World";

    public static String process(TestCase testCase) {
        final int N = testCase.N;

        switch (N) {
            case 1:
                return HELLO_WORLD;
            case 2: {
                final int A = unsafeGet(testCase.A, "A");
                final int B = unsafeGet(testCase.B, "B");
                return String.valueOf(A + B);
            }
            default: {
                throw unknownN(N);
            }
        }
    }

    private static int unsafeGet(Optional<Integer> argument, String argumentName) {
        return argument.orElseThrow(() -> new IllegalArgumentException("Missing Argument " + argumentName));
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

        switch (N) {
            case 1: {
                sc.close();
                return new TestCase(N);
            }
            case 2: {
                int A = sc.nextInt();
                int B = sc.nextInt();
                sc.close();
                return new TestCase(N, A, B);
            }
            default: {
                throw unknownN(N);
            }
        }
    }

    private static IllegalArgumentException unknownN(int N) {
        return new IllegalArgumentException("Unknown N: " + N);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final Optional<Integer> A;
        final Optional<Integer> B;

        public TestCase(int N) {
            this.N = N;
            this.A = Optional.empty();
            this.B = Optional.empty();
        }

        public TestCase(int N, int A, int B) {
            this.N = N;
            this.A = Optional.of(A);
            this.B = Optional.of(B);
        }
    }
}