import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long x = sc.nextLong();
        List<Long> a = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> a.add(sc.nextLong()));

        Collections.sort(a);

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (x < a.get(i)) {
                break;
            }
            x -= a.get(i);
            count++;
        }
        if (x == a.get(n - 1)) {
            count++;
        }
        System.out.println(count);
    }

}