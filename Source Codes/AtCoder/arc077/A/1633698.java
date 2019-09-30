import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    private static String solve(Scanner scanner) {
        int N = Integer.parseInt(scanner.nextLine());
        String[] nums = scanner.nextLine().split(" ");

        LinkedList<String> result = new LinkedList<>();

        for (int i = 0; i < N; i ++) {
            if (i % 2 == 1) {
                result.addLast(nums[i]);
            } else {
                result.addFirst(nums[i]);
            }
        }

        if (N % 2 == 0) {
            Collections.reverse(result);
        }

        return result.stream().collect(Collectors.joining(" "));
    }

    private static final String ex1 = "4\n" +
            "1 2 3 4";
    private static final String ex2 = "3\n" +
            "1 2 3";
    private static final String ex3 = "1\n" +
            "1000000000";
    private static final String ex4 = "6\n" +
            "0 6 7 6 7 0";

    public static void main(String[] args) {
//        System.out.println(solve(new Scanner(ex1)));
//        System.out.println(solve(new Scanner(ex2)));
//        System.out.println(solve(new Scanner(ex3)));
//        System.out.println(solve(new Scanner(ex4)));

        System.out.println(solve(new Scanner(System.in)));
    }

    private static int[] lineToIntNums(String line) {
        String[] strNums = line.split(" ");
        int[] ret = new int[strNums.length];
        for (int i = 0; i < strNums.length; i ++) {
            ret[i] = Integer.parseInt(strNums[i]);
        }
        return ret;
    }

    private static long[] lineToLongNums(String line) {
        String[] strNums = line.split(" ");
        long[] ret = new long[strNums.length];
        for (int i = 0; i < strNums.length; i ++) {
            ret[i] = Long.parseLong(strNums[i]);
        }
        return ret;
    }
}