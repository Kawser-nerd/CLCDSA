import java.io.ByteArrayInputStream;
import java.io.UnsupportedEncodingException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    private static String solve(Scanner scanner) {
        boolean ret = solveInner(scanner);
        return ret ? "POSSIBLE" : "IMPOSSIBLE";
    }

    private static boolean solveInner(Scanner scanner) {
        String line = scanner.nextLine();
        int N = Integer.parseInt(line.split(" ")[0]);
        int M = Integer.parseInt(line.split(" ")[1]);
        HashMap<Integer, HashSet<Integer>> islandToIslands = new HashMap<>();

        for (int i = 0; i < M; i ++) {
            line = scanner.nextLine();
            String[] split = line.split(" ");
            int a = Integer.parseInt(split[0]);
            int b = Integer.parseInt(split[1]);

            HashSet<Integer> set = islandToIslands.getOrDefault(a, new HashSet<>());
            set.add(b);
            islandToIslands.put(a, set);
        }

        HashSet<Integer> neighbors = islandToIslands.getOrDefault(1, new HashSet<>());
        for (Integer n: neighbors) {
            HashSet<Integer> set = islandToIslands.get(n);
            if (set == null) continue;
            if (set.contains(N)) return true;
        }

        return false;
    }

    public static void main(String[] args) {
//        tests();

        Scanner scanner = new Scanner(System.in);
        System.out.println(solve(scanner));
    }

    private static String ex1 = "3 2\n" +
            "1 2\n" +
            "2 3";
    private static String ex2 = "4 3\n" +
            "1 2\n" +
            "2 3\n" +
            "3 4";
    private static String ex3 = "100000 1\n" +
            "1 99999";
    private static String ex4 = "5 5\n" +
            "1 3\n" +
            "4 5\n" +
            "2 3\n" +
            "2 4\n" +
            "1 4";

    private static void tests() {
        System.out.println(solve(new Scanner(testCaseToInputStream(ex1))));
        System.out.println(solve(new Scanner(testCaseToInputStream(ex2))));
        System.out.println(solve(new Scanner(testCaseToInputStream(ex3))));
        System.out.println(solve(new Scanner(testCaseToInputStream(ex4))));
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