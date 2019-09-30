import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static final int MAX_NUM_DIGIT_IN_BINARY = 40; // 10^12 < 2^40

    public static long process(TestCase testCase) {
        final long K = testCase.K;
        final List<Long> A = testCase.A;

        if (K == 0) {
            return A.stream().mapToLong(i -> i).sum();
        } else {
            return maxSumAfterXor(A, K);
        }
    }

    private static long maxSumAfterXor(List<Long> A, long K) {
        int[][] allDigits = covertToDigitsMatrix(A);
        final int N = A.size();

        long sum = 0;
        long base = 1L << MAX_NUM_DIGIT_IN_BINARY - 1;
        for (int j = 0; j < MAX_NUM_DIGIT_IN_BINARY; ++j) {
            int count = countOnes(allDigits, j);
            boolean isWithinK = base <= K;
            if (isWithinK) {
                int flippedCount = N - count;

                boolean shouldFlip = flippedCount > count;
                if (shouldFlip) {
                    count = flippedCount;
                    K -= base;
                }
            }
            sum += count * base;
            base = base >> 1;
        }
        return sum;
    }

    private static int countOnes(int[][] allDigits, int j) {
        return Arrays.stream(allDigits)
                .mapToInt(digits -> digits[j])
                .sum();
    }

    private static int[][] covertToDigitsMatrix(List<Long> A) {
        int[][] allDigits = new int[A.size()][MAX_NUM_DIGIT_IN_BINARY];
        for (int i = 0; i < A.size(); ++i) {
            String digits = Long.toBinaryString(A.get(i));
            final int numDigits = digits.length();
            for (int j = numDigits - 1; j >= 0; --j) {
                final int rightAlignedIndex = MAX_NUM_DIGIT_IN_BINARY - numDigits + j;
                final char digit = digits.charAt(j);
                allDigits[i][rightAlignedIndex] = Character.getNumericValue(digit);
            }
        }
        return allDigits;
    }

    // util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final long result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        long K = sc.nextLong();
        List<Long> A = new ArrayList<>();
        for (long i = 0; i < N; ++i) {
            A.add(sc.nextLong());
        }

        sc.close();
        return new TestCase(N, K, A);
    }

    private static void output(long result) {
        System.out.println(result);
    }

    public static class TestCase {
        final long N;
        final long K;
        final List<Long> A;

        public TestCase(long N, long K, List<Long> A) {
            this.N = N;
            this.K = K;
            this.A = A;
        }
    }
}