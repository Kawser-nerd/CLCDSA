import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int N = sc.nextInt();
            Map<Long, Integer> cnt = new HashMap<>();
            Set<Long> set = new HashSet<>();
            for (int i = 0; i < N; i++) {
                long x = sc.nextLong();
                int nowCnt = cnt.getOrDefault(x, 0);
                nowCnt++;
                cnt.put(x, nowCnt);
                set.add(x);
            }

            List<Long> sortList = new ArrayList<>(set);
            sortList.sort(Long::compareTo);

            long ans = 0;
            List<Long> hen = new ArrayList<>();

            for (int i = sortList.size() - 1; hen.size() < 2 && i >= 0; i--) {
                long len = sortList.get(i);
                if ( cnt.get(len) >= 2 ) {
                    hen.add(len);
                }
                if ( cnt.get(len) >= 4 ) {
                    hen.add(len);
                }
            }
            if ( hen.size() >= 2 ) {
                ans = hen.get(0) * hen.get(1);
            }

            System.out.println(ans);
        }
    }
}