import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        Set<Integer> cnt = new HashSet<>();
        for (int i = 0; i < N; i++) {
            int a = sc.nextInt();

            if(cnt.contains(a)){
                cnt.remove(a);
            } else {
                cnt.add(a);
            }
        }

        out.println(cnt.size());
    }
}