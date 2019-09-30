import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

import static java.util.stream.Collectors.*;
import static java.util.stream.IntStream.range;

public class Main {
    final static PrintStream so = System.out;
    final static Scanner sc = new Scanner(System.in);
    static final String PLUS = "p";

    public static void main(String[] args) {
        int[] digits = sc.next().chars().map(i -> i-'0').toArray(); // 125 -> {1, 2, 5}

        int minBits = 0;
        int supBits = 1 << (digits.length-1);
        
        long ans = range(minBits, supBits).mapToObj(bits -> toExprOfAddition(digits, bits))
                                          .mapToLong(expr -> eval(expr))
                                          .sum();
        so.println(ans);
    }
    
    static String toExprOfAddition(int[] nums, int bits) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < nums.length; i++) {
            sb.append(nums[i]);
            if ((bits >> i & 1) == 1) {
                sb.append(PLUS);
            }
        }
        return sb.toString();
//        return range(0, nums.length).mapToObj(i -> nums[i] + ((bits >> i & 1) == 1 ? PLUS : ""))
//                                    .collect(joining());
    }
    
    static long eval(String exprOfAddition) {
        return Arrays.stream(exprOfAddition.split(PLUS)).mapToLong(Long::parseLong).sum();
    }
}