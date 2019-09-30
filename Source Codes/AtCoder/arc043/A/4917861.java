import java.util.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), a = scanner.nextInt(), b = scanner.nextInt();
        int[] s = java.util.stream.IntStream.range(0, n).map(i -> scanner.nextInt()).toArray();
        double d = Arrays.stream(s).max().getAsInt() - Arrays.stream(s).min().getAsInt();
        System.out.println(d == 0 ? -1 : b / d + " " + (a - Arrays.stream(s).average().getAsDouble() * b / d));
    }
}