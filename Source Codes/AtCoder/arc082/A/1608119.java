import java.util.HashMap;
import java.util.Scanner;
import java.util.StringJoiner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        StringJoiner sj = new StringJoiner("\n");
        for (int i = 0; i < 2; i ++) {
            sj.add(scanner.nextLine());
        }

        System.out.println(solve(sj.toString()));
    }

    private static int solve(String stdinString) {
        String[] splits = stdinString.split("\n");
        int N = Integer.parseInt(splits[0]);
        int[] nums = new int[N];

        splits = splits[1].split(" ");
        for (int i = 0; i < N; i ++) {
            nums[i] = Integer.parseInt(splits[i]);
        }

        int max = Integer.MIN_VALUE;
        HashMap<Integer, Integer> xCounts = new HashMap<>();
        for (int i = 0; i < N; i ++) {
            xCounts.put(nums[i] - 1, xCounts.getOrDefault(nums[i] - 1, 0) + 1);
            max = Math.max(max, xCounts.get(nums[i] - 1));

            xCounts.put(nums[i], xCounts.getOrDefault(nums[i], 0) + 1);
            max = Math.max(max, xCounts.get(nums[i]));

            xCounts.put(nums[i] + 1, xCounts.getOrDefault(nums[i] + 1, 0) + 1);
            max = Math.max(max, xCounts.get(nums[i] + 1));
        }

        return max;
    }

    private static String ex1 = "7\n3 1 4 1 5 9 2";
    private static String ex2 = "10\n0 1 2 3 4 5 6 7 8 9";
    private static String ex3 = "1\n99999";

    private static void tests() {
        System.out.println(solve(ex1));
        System.out.println(solve(ex2));
        System.out.println(solve(ex3));
    }
}