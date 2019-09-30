import java.util.Scanner;

public class Main {
    public static int process(TestCase testCase) {
        int X = testCase.X;
        int Y = testCase.Y;

        return X + Y / 2;
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

        int X = sc.nextInt();
        int Y = sc.nextInt();

        sc.close();
        return new TestCase(X, Y);
    }

    private static void output(int result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int X;
        final int Y;

        public TestCase(int X, int Y) {
            this.X = X;
            this.Y = Y;
        }
    }
}