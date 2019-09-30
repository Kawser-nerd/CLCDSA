import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> l = new ArrayList<>();
        List<Integer> r = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> {
            l.add(sc.nextInt());
            r.add(sc.nextInt());
        });

        int count = 0;
        for (int i = 0; i < n; i++) {
            count += r.get(i) - l.get(i) + 1;
        }
        System.out.println(count);
    }

}