import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }
        Collections.sort(a);
        int m = a.get(0);
        for (int i = 1; i < n; i++) {
            m = gcd(m, a.get(i));
        }
        if (k % m == 0 && a.get(n - 1) >= k) {
            System.out.println("POSSIBLE");
            return;
        }
        System.out.println("IMPOSSIBLE");
    }
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}