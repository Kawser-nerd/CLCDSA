import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[]$) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(), a[] = IntStream.range(0, n).map(i -> scanner.nextInt()).toArray();
        System.out.println(IntStream.range(0, n).mapToLong(i -> IntStream.range(0, n).filter(j -> i != j && a[i] % a[j] == 0).count()).mapToDouble(count -> count % 2 == 0 ? (count / 2d + 1) / (count + 1) : 1 / 2D).sum());
    }
}