import java.util.Scanner;
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int l = sc.nextInt();
        int h = sc.nextInt();
        int n = sc.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = a.get(i);
            if (l <= x && x <= h) {
                ans.add(0);
            } else if (x < l) {
                ans.add(l - x);
            } else if (x > h) {
                ans.add(-1);
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(ans.get(i));
        }
    }
}