import java.util.*;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        Arrays.sort(a);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 == n && x == a[i]) {
                ans++;
            } else if (i + 1 != n && x >= a[i]) {
                ans++;
                x -= a[i];
            } else {
                break;
            }
        }
        System.out.println(ans);
    }

}