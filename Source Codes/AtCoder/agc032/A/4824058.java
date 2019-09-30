import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            b.add(sc.nextInt());
        }

        int[] ans = new int[n];
        int k = 0;
        for (int i = 0; i < n; i++) {
            boolean ok = false;
            for (int j = b.size(); j > 0; j--) {
                if (b.get(j - 1).equals(j)) {
                    b.remove(j - 1);
                    ans[k++] = j;
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                System.out.println(-1);
                return;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            System.out.println(ans[i]);
        }
    }
}