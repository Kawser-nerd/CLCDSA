import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    private static final long MOD = 1000000007;

    private static long[] factorial;
    private static long[] inverseFactorial;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int rows = Integer.parseInt(st.nextToken());
        int columns = Integer.parseInt(st.nextToken());
        int ignoreRows = Integer.parseInt(st.nextToken());
        int ignoreColumns = Integer.parseInt(st.nextToken());

        int totalDownMoves = rows - 1;
        int totalRightMoves = columns - 1;
        int totalMoves = totalDownMoves + totalRightMoves;
        computeFactorials(totalMoves);
        computeInverseFactorials(totalMoves);

        long count = countCombinationWithRepetition(totalMoves, totalDownMoves, totalRightMoves);

        int maxDownLimit = rows - ignoreRows - 1;
        int minRightLimit = ignoreColumns - 1;
        int sumLimits = maxDownLimit + minRightLimit;
        for (int downMoves = 0; downMoves <= sumLimits; downMoves++) {
            int rightMoves = sumLimits - downMoves;
            // Cannot occur
            int remainingMoves = totalMoves - downMoves - rightMoves;
            long numWaysToReachHere = countCombinationWithRepetition(sumLimits, downMoves, rightMoves);

            // cannot occur
            if (downMoves < maxDownLimit && rightMoves < minRightLimit) {
                continue;
            }
            // cannot occur
            if (downMoves < maxDownLimit && rightMoves == minRightLimit) {
                continue;
            }
            // Valid
            if (downMoves < maxDownLimit && rightMoves > minRightLimit) {
                continue;
            }


            // cannot occur
            if (downMoves == maxDownLimit && rightMoves < minRightLimit) {
                continue;
            }
            // Necessarily have to move right so count out all moves that took next step as down
            if (downMoves == maxDownLimit && rightMoves == minRightLimit) {
                // Cannot make another right move, illegal state
                if (rightMoves + 1 > totalRightMoves) {
                    System.out.println(0);
                    return;
                }

                if (totalDownMoves - downMoves < 0 || totalRightMoves - rightMoves < 0) {
                    continue;
                }

                long ignoreWays = countWays(
                        numWaysToReachHere,
                        // -1 accounts for the right move made
                        totalMoves - sumLimits - 1,
                        totalDownMoves - downMoves - 1,
                        totalRightMoves - rightMoves
                );
                count = modularSubtraction(count, ignoreWays);
                continue;
            }
            // cannot occur
            if (downMoves == maxDownLimit && rightMoves > minRightLimit) {
                continue;
            }

            if (downMoves > maxDownLimit && rightMoves < minRightLimit) {
                if (totalDownMoves - downMoves < 0 || totalRightMoves - rightMoves < 0) {
                    continue;
                }
                long ignoreWays = countWays(
                        numWaysToReachHere,
                        remainingMoves,
                        totalDownMoves - downMoves,
                        totalRightMoves - rightMoves
                );
                count = modularSubtraction(count, ignoreWays);
                continue;
            }
            // cannot occur
            if (downMoves > maxDownLimit && rightMoves == minRightLimit) {
                continue;
            }
            // cannot occur
            if (downMoves > maxDownLimit && rightMoves > minRightLimit) {
                continue;
            }

        }
        System.out.println(count);
    }

    private static long countWays(long waysSoFar, int totalMoves, int downMoves, int rightMoves){
        long waysRemaining = countCombinationWithRepetition(totalMoves, downMoves, rightMoves);
        return (waysSoFar * waysRemaining) % MOD;
    }

    private static long countCombinationWithRepetition(int total, int type1, int type2) {
        return (((factorial[total] * inverseFactorial[type1]) % MOD) * inverseFactorial[type2]) % MOD;
    }

    private static long modularSubtraction(long num1, long num2) {
        if (num1 < num2) {
            num1 += MOD;
        }
        return (num1 - num2) % MOD;
    }

    private static void computeInverseFactorials(int limit) {
        inverseFactorial = new long[limit + 1];
        for (int i = 0; i <= limit; i++) {
            inverseFactorial[i] = modularExponentiation(factorial[i], MOD - 2);
        }
    }

    private static long modularExponentiation(long base, long exponent) {
        if (exponent == 1) {
            return base % MOD;
        }
        long squareRoot = exponent / 2;
        long value = modularExponentiation(base, squareRoot);
        value *= value;
        value %= MOD;
        if (exponent % 2 == 1) {
            value *= base;
            value %= MOD;
        }
        return value;
    }

    private static void computeFactorials(int limit) {
        factorial = new long[limit + 1];
        factorial[0] = 1;
        for (int i = 1; i <= limit; i++) {
            factorial[i] = (factorial[i - 1] * i) % MOD;
        }
    }
}