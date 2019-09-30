import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        String[] ss = new String[n];
        for (int i = 0; i < n; i++) {
            ss[i] = in.nextLine();
        }
        String ans = ss[0];
        for (String s : ss) {
            ans = same(ans, s);
        }
        char[] ch = ans.toCharArray();
        Arrays.sort(ch);
        System.out.println(new String(ch));
    }

    public static String same(String s1, String s2) {
        String ans = "";
        for (int i = 0; i < 26; i++) {
            int c1 = 0, c2 = 0;
            for (char c : s1.toCharArray()) {
                if (c == 'a' + i)
                    c1++;
            }
            for (char c : s2.toCharArray()) {
                if (c == 'a' + i)
                    c2++;
            }
            for (int j = 0; j < Math.min(c1, c2); j++) {
                ans += (char) ('a' + i);
            }
        }
        return ans;
    }
}