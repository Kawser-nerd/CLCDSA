import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
            b.add(sc.nextInt());
        }
        Collections.sort(a, Comparator.reverseOrder());
        int aMax = a.get(0);
        Collections.sort(b, Comparator.reverseOrder());

        int ans = 0;
        for (int i : b) {
            if (i < aMax || h <= 0) {
                break;
            }
            h -= i;
            ans++;
        }
        if (h <= 0) {
            System.out.println(ans);
            return;
        }
        if (h % aMax == 0) {
            ans += h / aMax;
        } else {
            ans += h / aMax + 1;
        }
        System.out.println(ans);
    }
}