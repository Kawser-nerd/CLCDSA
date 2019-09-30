import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        boolean ans = true;
        for (int i = 3; i <= Math.sqrt(n); i += 2) if (!(ans = n % i != 0)) break;
        System.out.println(n == 2 || n != 1 && (ans && n % 2 == 1 || Integer.toString(n).chars().map(c -> c - '0').sum() % 3 != 0 && java.util.Arrays.asList(1, 3, 7, 9).contains(n % 10)) ? "Prime" : "Not Prime");
    }
}