import java.util.Scanner;

public class Main {

    private static final String YES = "Yes";
    private static final String NO = "No";

    public static String process(TestCase testCase) {
        final int A = testCase.A;
        final int B = testCase.B;

        return areBothOdd(A, B) ? YES : NO;
    }

    private static boolean areBothOdd(int A, int B) {
        return isOdd(A) && isOdd(B);
    }

    private static boolean isOdd(int n) {
        return n % 2 != 0;
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final String result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();

        return new TestCase(A, B);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int A;
        final int B;

        public TestCase(int A, int B) {
            this.A = A;
            this.B = B;
        }
    }
}