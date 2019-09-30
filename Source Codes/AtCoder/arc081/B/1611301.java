import java.io.ByteArrayInputStream;
import java.io.UnsupportedEncodingException;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    private static long solve(Scanner scanner) {
        scanner.nextLine();
        String s1 = scanner.nextLine();
        String s2 = scanner.nextLine();

        boolean lastPattern;
        boolean pattern;
        int pointer;
        long ret;

        if (s1.charAt(0) == s2.charAt(0)) {
            lastPattern = true;
            pointer = 1;
            ret = 3;
        } else {
            lastPattern = false;
            pointer = 2;
            ret = 6;
        }

        while(pointer < s1.length()) {
            pattern = s1.charAt(pointer) == s2.charAt(pointer);

            if (lastPattern) {
//                ret *= 2;
                ret = mod1000000007(ret, 2L);
            } else if (pattern) {
                ret = ret;
            } else {
//                ret *= 3;
                ret = mod1000000007(ret, 3L);
            }

            pointer += pattern ? 1 : 2;

            lastPattern = pattern;
        }

        return ret % 1000000007;
    }

    private static long mod1000000007(long a, long b) {
        return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
    }

    public static void main(String[] args) {
//        tests();

        Scanner scanner = new Scanner(System.in);
        System.out.println(solve(scanner));
    }

    private static String ex1 = "3\n" +
            "aab\n" +
            "ccb";
    private static String ex2 = "1\n" +
            "Z\n" +
            "Z";
    private static String ex3 = "52\n" +
            "RvvttdWIyyPPQFFZZssffEEkkaSSDKqcibbeYrhAljCCGGJppHHn\n" +
            "RLLwwdWIxxNNQUUXXVVMMooBBaggDKqcimmeYrhAljOOTTJuuzzn";

    private static String ex4 = "3\n" +
            "aabd\n" +
            "ccbd";
    private static String ex5 = "3\n" +
            "aabdee\n" +
            "ccbdff";

    private static void tests() {
        System.out.println(solve(new Scanner(testCaseToInputStream(ex1))));
        System.out.println(solve(new Scanner(testCaseToInputStream(ex2))));
        System.out.println(solve(new Scanner(testCaseToInputStream(ex3))));
        System.out.println(solve(new Scanner(testCaseToInputStream(ex4))));
        System.out.println(solve(new Scanner(testCaseToInputStream(ex5))));
    }

    private static ByteArrayInputStream testCaseToInputStream(String ex) {
        try {
            return new ByteArrayInputStream(ex.getBytes("utf-8"));
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
            throw new RuntimeException();
        }
    }

    private static int[] lineTointNums(String line) {
        String[] numStrs = line.split(" ");
        int[] nums = new int[numStrs.length];
        for (int i = 0; i < nums.length; i ++) {
            nums[i] = Integer.parseInt(numStrs[i]);
        }
        return nums;
    }
}