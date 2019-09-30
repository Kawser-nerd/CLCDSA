import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        List<Integer> list = Arrays.asList(1, 2, 3, 4, 5, 6);
        Collections.rotate(list, -n / 5);
        for (int i = 0; i < n % 5; i++)
            Collections.swap(list, i, (i + 1) % 5);
        list.forEach(System.out::print);
        System.out.println();
    }
}