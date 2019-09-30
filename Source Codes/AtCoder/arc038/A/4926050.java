import java.util.*;
import java.util.stream.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), a[] = IntStream.range(0, n).map(i -> scanner.nextInt()).sorted().toArray();
        System.out.println(IntStream.range(0, n).filter(i -> i % 2 != n % 2).map(i -> a[i]).sum());
    }
}