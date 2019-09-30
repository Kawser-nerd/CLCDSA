import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
    private static Scanner scanner = new Scanner(System.in);

    static String s;
    public static void main(String[]$) {
        int n = scanner.nextInt(), k = scanner.nextInt();
        char[] c = (s = scanner.next()).toCharArray();
        Arrays.sort(c);
        String ans = "";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (c[j] != ' ' && count(ans, c, c[j]) <= k) {
                    ans += c[j];
                    c[j] = ' ';
                    break;
                }
        System.out.println(ans);
    }

    static int count(String ans, char[] c, char ch) {
        int d = (int)IntStream.range(0, ans.length()).filter(i -> s.charAt(i) != ans.charAt(i)).count() + (ch == s.charAt(ans.length()) ? 0 : 1);
        int[] a = new int[26];
        for (char b : c)
            if (b != ' ')
                a[b - 'a']++;
        a[ch - 'a']--;
        for (char b : s.substring(ans.length() + 1).toCharArray())
            if (a[b - 'a'] > 0) a[b - 'a']--;
            else d++;
        return d;
    }
}