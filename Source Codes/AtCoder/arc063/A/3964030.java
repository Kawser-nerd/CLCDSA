import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        int cnt = 0;
        Character crr = s.charAt(0);
        Character nxt;
        for (int i = 1; i < n; i++) {
            nxt = s.charAt(i);
            if (crr != nxt) {
                cnt++;
            }
            crr = nxt;
        }
        System.out.println(cnt);
    }
}