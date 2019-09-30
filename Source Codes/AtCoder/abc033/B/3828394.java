import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<String> s = new ArrayList<>();
        List<Integer> p = new ArrayList<>();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            s.add(sc.next());
            int x = sc.nextInt();
            p.add(x);
            sum += x;
        }

        String ans = "atcoder";
        for (int i = 0; i < n; i++) {
            if (p.get(i) * 2 > sum) {
                ans = s.get(i);
            }
        }

        System.out.println(ans);
    }
}