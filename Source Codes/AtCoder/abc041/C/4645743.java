import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        long[] heights = new long[N];
        HashMap<Long, Integer> heightToNumber = new HashMap<>();

        for (int i = 0; i < N; i++) {
            heights[i] = sc.nextLong();
            heightToNumber.put(heights[i], i);
        }
        Arrays.parallelSort(heights);

        for (int i = N-1; i >= 0; i--) {
            System.out.println(heightToNumber.get(heights[i]) + 1);
        }
    }

}