import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        List<Integer> kushi = new ArrayList<>();
        for (int i = 0; i < 2 * N; i++) {
            kushi.add(scan.nextInt());
        }
        kushi.sort(Comparator.naturalOrder());
        int total = 0;
        int idx = 0;
        for (Integer l : kushi) {
            if (idx % 2 == 0) {
                total += l;
            }
            idx++;
        }
        System.out.println(total);
    }
}