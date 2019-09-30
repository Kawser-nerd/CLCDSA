import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int e = sc.nextInt();
        Set<Integer> ans = new TreeSet<>();
        ans.add(a + b + c);
        ans.add(a + b + d);
        ans.add(a + b + e);
        ans.add(a + c + d);
        ans.add(a + c + e);
        ans.add(a + d + e);
        ans.add(b + c + d);
        ans.add(b + c + e);
        ans.add(b + d + e);
        ans.add(c + d + e);
        int cnt = 1;
        for (Integer x : ans) {
            if (cnt == ans.size() - 2) {
                System.out.println(x);
            }
            cnt++;
        }
    }
}