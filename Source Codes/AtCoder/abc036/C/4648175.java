import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();

        long[] values = new long[N];
        SortedSet<Long> distincts = new TreeSet<>();
        for (int i = 0; i < N; i++) {
            values[i] = sc.nextLong();
            distincts.add(values[i]);
        }

        HashMap<Long, Integer> rank = new HashMap<>();
        int index = 0;
        for (Long v: distincts) {
            rank.put(v, index);
            index++;
        }

        for (int i = 0; i < N; i++) {
            System.out.println(rank.get(values[i]));
        }

    }
}