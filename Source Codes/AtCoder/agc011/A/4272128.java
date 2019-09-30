import java.util.*;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Long c = sc.nextLong();
        Long k = sc.nextLong();
        List<Long> t = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> t.add(sc.nextLong()));
        Collections.sort(t);
        Deque<Long> queue = new ArrayDeque<>(t);

        Long count = 0L;
        while (queue.size() != 0) {
            count++;
            Long target = queue.remove();
            Long rider = 1L;
            while (queue.size() != 0 && queue.element() <= target + k && rider < c) {
                rider++;
                queue.remove();
            }
        }
        System.out.println(count);

    }

}