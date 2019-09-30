import java.util.*;

public class Main {
    public void main(Scanner sc) {
        String s = sc.next();
        int len = s.length();

        int ans = len;
        int index = 0;
        while (true) {
            int next;
            char c = s.charAt(index);
            if (c == '0') {
                next = s.indexOf('1', index + 1);
            } else {
                next = s.indexOf('0', index + 1);
            }

            if (next == -1) {
                break;
            }

            ans = Math.min(ans, Math.max(next, len - next));
            index = next;
        }

        System.out.println(ans);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}