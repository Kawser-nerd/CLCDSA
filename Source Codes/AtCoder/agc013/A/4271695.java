import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Long> a = new ArrayList<>();
        IntStream.range(0, n).forEach(i -> a.add(sc.nextLong()));

        final String INIT = "INIT";
        final String INC = "INCREMENT";
        final String DEC = "DECREMENT";
        Long prev = 0L;
        String state = INIT;
        Long count = 1L;
        for (int i = 0; i < a.size(); i++) {
            Long current = a.get(i);
            if (i == 0) {
                prev = current;
                continue;
            }
            if (state.equals(INIT)) {
                if (current > prev) {
                    state = INC;
                }
                if (current < prev) {
                    state = DEC;
                }
                prev = current;
                continue;
            }
            if (state.equals(INC) && current >= prev) {
                prev = current;
                continue;
            }
            if (state.equals(DEC) && current <= prev) {
                prev = current;
                continue;
            }
            prev = current;
            state = "INIT";
            count++;
        }
        System.out.println(count);
    }

}