import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Scanner;

public class Main {

    private static final String TLE = "TLE";

    public static String process(TestCase testCase) {
        final int N = testCase.N;
        final int T = testCase.T;
        final List<Integer> c = testCase.c;
        final List<Integer> t = testCase.t;

        Optional<Integer> minCost = Optional.empty();

        for (int i = 0; i < N; ++i) {
            final int cost = c.get(i);
            final int time = t.get(i);
            if (time <= T) {
                if (minCost.isPresent()) {
                    minCost = minCost.map(curr -> Math.min(curr, cost));
                } else {
                    minCost = Optional.of(cost);
                }
            }
        }

        return minCost.map(String::valueOf).orElse(TLE);
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
        int T = sc.nextInt();

        List<Integer> c = new ArrayList<>();
        List<Integer> t = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            c.add(sc.nextInt());
            t.add(sc.nextInt());
        }

        return new TestCase(N, T, c, t);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final int T;
        final List<Integer> c;
        final List<Integer> t;

        public TestCase(int N, int T, List<Integer> c, List<Integer> t) {
            this.N = N;
            this.T = T;
            this.c = c;
            this.t = t;
        }
    }
}