import java.util.*;
import java.util.stream.*;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt(), k = scanner.nextInt(), t[] = IntStream.range(0, n).map(i -> scanner.nextInt()).toArray();
        System.out.println(IntStream.rangeClosed(3, n).filter(i -> t[i - 3] + t[i - 2] + t[i - 1] < k).findFirst().orElse(-1));
    }
}