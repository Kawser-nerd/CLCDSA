import static java.util.function.Function.*;
import static java.util.stream.Collectors.*;

import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n = sc.nextInt();
        Integer a[] = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        long cnt = 0;
        for (long count : Arrays.stream(a).collect(groupingBy(identity(), counting())).values()) {
            cnt += (count - 1);
        }
        cnt += (cnt % 2);

        System.out.println(n - cnt);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}