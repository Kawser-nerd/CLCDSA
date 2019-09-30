import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int s = sc.nextInt();
        Set<Integer> set = new HashSet<>();
        int ans = 1;
        while (true) {
            set.add(s);
            if (s % 2 == 0) {
                s /= 2;
            } else {
                s = 3 * s + 1;
            }
            ans++;
            if (set.contains(s)) {
                System.out.println(ans);
                return;
            }
        }
    }
}