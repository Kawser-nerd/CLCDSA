import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {

    private static final String ZERO = "0";

    private enum Direction {
        W, E;
    }

    public static String process(TestCase testCase) {
        final int N = testCase.N;
        final String S = testCase.S;

        if (N <= 0) {
            return ZERO;
        } else {
            final List<Direction> directions = Arrays.stream(S.split(""))
                    .map(Direction::valueOf)
                    .collect(Collectors.toList());

            long min = IntStream.range(1, N)
                    .mapToObj(directions::get)
                    .filter(Direction.E::equals)
                    .count();

            long change = min;
            for (int i = 1; i < N; ++i) {
                final Direction prev = directions.get(i - 1);
                final Direction curr = directions.get(i);
                if (Direction.W.equals(prev)) {
                    change++;
                }
                if (Direction.E.equals(curr)) {
                    change--;
                }
                min = Math.min(min, change);
            }

            return String.valueOf(min);
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
        String S = sc.next();

        return new TestCase(N, S);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final String S;

        public TestCase(int N, String S) {
            this.N = N;
            this.S = S;
        }
    }
}