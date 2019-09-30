import java.util.*;

public class Main {
    private static int solve(Scanner scanner) {
        int N = Integer.parseInt(scanner.nextLine());
        int[] nums = lineToIntNums(scanner.nextLine());

        for (int i = 0; i < N; i ++) {
            nums[i] --;
        }

        int ret = 0;
        for (int i = 0; i < N; i ++) {
            if (nums[i] == i) {
                if (i == N - 1) {
                    swap(i - 1, i, nums);
                } else {
                    swap(i, i + 1, nums);
                }
                ret ++;
            }
        }

        return ret;
    }

    private static void swap(int i, int j, int[] nums) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    private static final String ex1 = "5\n" +
            "1 4 3 5 2";
    private static final String ex2 = "2\n" +
            "1 2";
    private static final String ex3 = "2\n" +
            "2 1";
    private static final String ex4 = "9\n" +
            "1 2 4 9 5 8 7 3 6";

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