import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;
import java.util.stream.IntStream;

public class Main {
    public static String process(TestCase testCase) {
        final String s = testCase.s;
        final int K = testCase.K;

        TreeSet<String> set = new TreeSet<>();
        final int length = s.length();
        IntStream.range(0, K + 1)
                .forEach(i ->
                        IntStream.range(0, length - i)
                                .forEach(j ->
                                        set.add(s.substring(j, j + i + 1))
                                )
                );

        return new ArrayList<>(set).get(K - 1);
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final String result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        int K = sc.nextInt();

        return new TestCase(s, K);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final String s;
        final int K;

        public TestCase(String s, int K) {
            this.s = s;
            this.K = K;
        }
    }
}