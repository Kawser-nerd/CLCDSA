import java.util.*;

/**
 * Created by nirpis.hu on 2019/3/9.
 */
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int p = sc.nextInt();
            if (s.contains(p)) {
                s.remove(p);
            } else {
                s.add(p);
            }
        }
        System.out.print(s.size());
    }

}