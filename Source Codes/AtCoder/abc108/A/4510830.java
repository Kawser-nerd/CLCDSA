import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
    public static String process(int K) {
        final int sum = IntStream.range(1, K + 1)
                .map(i -> ((K - i) + 1) / 2)
                .sum();

        return String.valueOf(sum);
    }

    // Util Func

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();

        // process
        final String result = process(K);

        // output
        System.out.println(result);
    }
}