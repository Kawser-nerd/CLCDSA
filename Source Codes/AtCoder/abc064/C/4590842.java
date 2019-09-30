import java.math.BigDecimal;
import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();

        HashSet<Integer> kinds = new HashSet<>();
        int any = 0;

        for (int i = 0; i < N; i++) {
            int value = sc.nextInt();

            if (value <= 399) {
                kinds.add(0);
            } else if (value <= 799) {
                kinds.add(1);
            } else if (value <= 1199) {
                kinds.add(2);
            } else if (value <= 1599) {
                kinds.add(3);
            } else if (value <= 1999) {
                kinds.add(4);
            } else if (value <= 2399) {
                kinds.add(5);
            } else if (value <= 2799) {
                kinds.add(6);
            } else if (value <= 3199) {
                kinds.add(7);
            } else {
                any++;
            }
        }

        int min = (kinds.size() == 0) ? 1 : kinds.size();
        int max = kinds.size() + any;

        System.out.println(min + " "+ max);
    }
}