import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static final String WAR = "War";
    public static final String NO_WAR = "No War";

    public static String process(TestCase testCase) {
        final int X = testCase.X;
        final int Y = testCase.Y;
        final int M = testCase.M;
        final int N = testCase.N;
        final List<Integer> x = testCase.x;
        final List<Integer> y = testCase.y;

        return warOrNoWar(isXSmallerThanY(X, Y), areAllCitiesWithinCondition(X, Y, x, y));
    }

    private static String warOrNoWar(Boolean... conditions) {
        final boolean areAllConditionsSatisfied = Arrays.stream(conditions).allMatch(Boolean::booleanValue);
        return areAllConditionsSatisfied ? NO_WAR : WAR;
    }

    private static boolean isXSmallerThanY(int X, int Y) {
        return X < Y;
    }

    private static boolean areAllCitiesWithinCondition(int X, int Y, List<Integer> x, List<Integer> y) {
        final int xMax = x.stream().mapToInt(i -> i).max().orElseThrow(() -> new IllegalArgumentException("x is empty"));
        final int yMin = y.stream().mapToInt(i -> i).min().orElseThrow(() -> new IllegalArgumentException("y is empty"));

        return xMax < yMin && xMax < Y && X < yMin;
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
        int M = sc.nextInt();
        int X = sc.nextInt();
        int Y = sc.nextInt();
        List<Integer> x = readList(sc, N);
        List<Integer> y = readList(sc, M);

        return new TestCase(N, M, X, Y, x, y);
    }

    private static List<Integer> readList(Scanner sc, int size) {
        return IntStream.range(0, size)
                .mapToObj(i -> sc.nextInt())
                .collect(Collectors.toList());
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final int M;
        final int X;
        final int Y;
        final List<Integer> x;
        final List<Integer> y;

        public TestCase(int N, int M, int X, int Y, List<Integer> x, List<Integer> y) {
            this.N = N;
            this.M = M;
            this.X = X;
            this.Y = Y;
            this.x = x;
            this.y = y;
        }
    }
}