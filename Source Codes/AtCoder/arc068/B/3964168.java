import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HashSet<Integer> hs = new HashSet<>();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            if (!hs.contains(a)) {
                ans++;
                hs.add(a);
            }
        }
        if ((ans & 1) == 0) {
            ans--;
        }
        System.out.println(ans);
    }
}