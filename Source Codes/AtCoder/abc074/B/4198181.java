import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> x = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> x.add(sc.nextInt()));

        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (x.get(i) < Math.abs(x.get(i) - k)) {
                sum += 2 * x.get(i);
                continue;
            }
            sum += 2 * Math.abs(x.get(i) - k);
        }
        System.out.println(sum);
    }

}