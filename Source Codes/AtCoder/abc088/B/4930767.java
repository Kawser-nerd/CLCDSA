import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int N, cnt = 0;
        Scanner scanner = new Scanner(System.in);

        List<Integer> numbers = new ArrayList<>();
        N = Integer.parseInt(scanner.next());

        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(scanner.next()));
        }

        numbers.sort(Comparator.reverseOrder());

        for (int i = 0; i < numbers.size(); i++) {
            if (i % 2 == 0) {
                cnt += numbers.get(i);
            } else {
                cnt -= numbers.get(i);
            }
        }

        System.out.println(cnt);
    }
}