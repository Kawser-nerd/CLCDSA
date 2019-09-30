import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static String process(TestCase testCase) {
        final int A = testCase.A;
        final int B = testCase.B;
        final int C = testCase.C;

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> Integer.compare(b, a));
        pq.add(A);
        pq.add(B);
        pq.add(C);

        int max = noInspectionGet(pq);
        final int smaller = noInspectionGet(pq);
        final int smallest = noInspectionGet(pq);

        return String.valueOf(max * 10 + smaller + smallest);
    }

    private static int noInspectionGet(PriorityQueue<Integer> pq) {
        // impossible, input are never null
        //noinspection ConstantConditions
        return pq.poll();
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
        int C = sc.nextInt();

        return new TestCase(A, B, C);
    }

    private static void output(String result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int A;
        final int B;
        final int C;

        public TestCase(int A, int B, int C) {
            this.A = A;
            this.B = B;
            this.C = C;
        }
    }
}