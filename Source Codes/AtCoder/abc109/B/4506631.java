import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {

    private static final String YES = "Yes";
    private static final String NO = "No";

    public static String process(TestCase testCase) {
        final int N = testCase.N;
        final List<String> W = testCase.W;

        final Set<String> announced = new HashSet<>(Collections.singletonList(W.get(0)));

        return IntStream.range(1, N)
                .allMatch(i -> {
                    final String prev = W.get(i - 1);
                    final String curr = W.get(i);
                    final boolean notAnnounced = !announced.contains(curr);
                    final boolean charSatisfied = curr.charAt(0) == prev.charAt(prev.length() - 1);

                    announced.add(curr);
                    return notAnnounced && charSatisfied;
                })
                ? YES
                : NO;
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
        final List<String> W = IntStream.range(0, N).mapToObj(i -> sc.next()).collect(Collectors.toList());

        return new TestCase(N, W);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final List<String> W;

        public TestCase(int N, List<String> W) {
            this.N = N;
            this.W = W;
        }
    }
}