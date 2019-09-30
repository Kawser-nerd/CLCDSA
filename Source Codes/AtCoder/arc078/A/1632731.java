import java.util.*;

public class Main {
    private static long solve(Scanner scanner) {
        int N = Integer.parseInt(scanner.nextLine());
        long[] a = lineToNums(scanner.nextLine());

        long sumAll = Arrays.stream(a).sum();

        long[] xSum = new long[N];
        long[] ySum = new long[N];

        xSum[0] = a[0];
        ySum[0] = sumAll - xSum[0];

        long ret = Math.abs(xSum[0] - ySum[0]);

        for (int i = 1; i < N - 1; i ++) {
            xSum[i] = xSum[i - 1] + a[i];
            ySum[i] = sumAll - xSum[i];
            ret = Math.min(ret, Math.abs(xSum[i] - ySum[i]));
        }

        return ret;
    }

    private static final String ex1 = "6\n" +
            "1 2 3 4 5 6";
    private static final String ex2 = "2\n" +
            "10 -10";

    public static void main(String[] args) {
        System.out.println(solve(new Scanner(System.in)));
    }

    private static long[] lineToNums(String line) {
        String[] strNums = line.split(" ");
        long[] ret = new long[strNums.length];
        for (int i = 0; i < strNums.length; i ++) {
            ret[i] = Long.parseLong(strNums[i]);
        }
        return ret;
    }
}