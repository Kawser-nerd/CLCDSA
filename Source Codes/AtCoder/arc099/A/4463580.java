import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static final int MINIMUM = 1;

    public static String process(TestCase testCase) {
        final int N = testCase.N;
        final int K = testCase.K;

        return String.valueOf(numOpsNeeded(K, N - 1));

//        final List<Integer> A = testCase.A;
//
//        long count = 0, op = 0;
//        for (int i = 0; i < N; ++i) {
//            if (A.get(i) == MINIMUM) {
//                if (count >= K - 2) {
//                    op = op + numOpsNeeded(K, count);
//                    count = 0;
//                }
//            } else {
//                count++;
//            }
//        }
//        op = op + numOpsNeeded(K, count);
//        return String.valueOf(op);
    }

    private static long numOpsNeeded(int k, long count) {
        return (count + (k - 1) - 1) / (k - 1);
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
        int K = sc.nextInt();

        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < N; ++i) {
            A.add(sc.nextInt());
        }

        return new TestCase(N, K, A);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final int K;
        final List<Integer> A;

        public TestCase(int N, int K, List<Integer> A) {
            this.N = N;
            this.K = K;
            this.A = A;
        }
    }
}