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

        numbers.sort(Comparator.naturalOrder());
        int max = 0;
        for(int num : numbers) {
            if (max < num) {
                max = num;
                cnt++;
            }
        }
        System.out.println(cnt);
    }
}