import java.util.*;

public class Main {
    public static void main(String[] args) {
        int N = 0;
        Scanner scanner = new Scanner(System.in);

        Set<Integer> numbers = new HashSet<>();
        N = Integer.parseInt(scanner.next());

        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(scanner.next()));
        }

        System.out.println(numbers.size());
    }
}