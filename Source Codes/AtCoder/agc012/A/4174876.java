import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Long> a = new ArrayList<>();
        IntStream.range(0, 3 * n).forEach(i -> a.add(sc.nextLong()));

        Collections.sort(a);
        long sum = 0;
        for (int i = 0; i < 3 * n; i++) {
            if (i < n) {
                continue;
            }
            if ((i - n) % 2 == 1) {
                continue;
            }
            sum += a.get(i);
        }
        System.out.println(sum);
    }

}