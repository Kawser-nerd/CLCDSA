import java.util.Scanner;

public class Main {
    private static final int FAVOURITE_NUMBER = 753;

    public static int process(TestCase testCase) {
        String S = testCase.S;
        int min = Integer.MAX_VALUE;

        for (int i = 2, length = S.length(); i < length; ++i) {
            final int num = Integer.valueOf(S.substring(i - 2, i + 1));
            min = Math.min(min, diff(num));
        }
        return min;
    }

    private static int diff(int num) {
        return Math.abs(FAVOURITE_NUMBER - num);
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final int result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        String S = sc.next();

        sc.close();
        return new TestCase(S);
    }

    private static void output(int result) {
        System.out.println(result);
    }

    public static class TestCase {
        final String S;

        public TestCase(String S) {
            this.S = S;
        }
    }
}