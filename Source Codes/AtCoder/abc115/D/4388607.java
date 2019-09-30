import java.util.Scanner;

public class Main {
    private static final long FIRST_SLICE_IS_BUN = 1;
    private static final long MIDDLE_PATTY = 1;

    public static long process(TestCase testCase) {
        final int N = testCase.N;
        final long X = testCase.X;

        return countNumPatty(N, X);
    }

    private static long countNumPatty(int N, long X) {
        if (X == 0) {
            return 0L;
        }

        final long burgerLength = burgerLength(N);
        boolean isWholeBurgerEaten = X >= burgerLength;
        if (isWholeBurgerEaten) {
            return numPatty(N);
        } else {
            // countPartialBurger
            boolean isOnlyTopSliceRemaining = X == burgerLength - 1;

            final long oneSmallerLayerLength = burgerLength(N - 1);
            final long oneSmallerLayerPatty = numPatty(N - 1);
            if (isOnlyTopSliceRemaining) {
//                return 2 * oneSmallerLayerPatty + MIDDLE_PATTY; // Top slice is bun
                return numPatty(N); // Top slice is bun
            } else {
                boolean canFinishHalfBurger = X >= (burgerLength - FIRST_SLICE_IS_BUN - oneSmallerLayerLength);
                if (canFinishHalfBurger) {
                    return oneSmallerLayerPatty + MIDDLE_PATTY + countNumPatty(N - 1, X - FIRST_SLICE_IS_BUN - oneSmallerLayerLength - MIDDLE_PATTY);
                } else {
                    boolean canFinishOneSmallerLayer = (X - FIRST_SLICE_IS_BUN) >= (FIRST_SLICE_IS_BUN + oneSmallerLayerLength);
                    if (canFinishOneSmallerLayer) {
                        return oneSmallerLayerPatty;
                    } else {
                        boolean canEatSomePatty = X > FIRST_SLICE_IS_BUN;
                        if (canEatSomePatty) {
                            return countNumPatty(N - 1, X - FIRST_SLICE_IS_BUN);
                        } else {
                            return 0L;
                        }
                    }
                }
            }

        }
    }

    private static long burgerLength(int layer) {
        return (long) Math.pow(2, layer + 2) - 3L;
    }

    private static long numPatty(int layer) {
        return (long) Math.pow(2, layer + 1) - 1L;
    }

    // Util func

    public static void main(String[] args) {
        TestCase testCase = readFromInput();

        final long result = process(testCase);

        output(result);
    }

    private static TestCase readFromInput() {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        long X = sc.nextLong();

        sc.close();
        return new TestCase(N, X);
    }

    private static void output(long result) {
        System.out.println(result);
    }

    public static class TestCase {
        final int N;
        final long X;

        public TestCase(int N, long X) {
            this.N = N;
            this.X = X;
        }
    }
}