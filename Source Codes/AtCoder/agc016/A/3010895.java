import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        List<Character> str = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            str.add(s.charAt(i));
        }
        int min = 101;
        for (char i = 'a'; i <= 'z'; i++) {
            min = Math.min(min, solve(str, i));
        }
        System.out.println(min);
    }
    private static int solve(List<Character> str, char ch) {
        boolean can = true;
        char x = str.get(0);
        for (Character it : str) {
            if (it != x) {
                can = false;
            }
        }
        if (can) {
            return 0;
        }
        List<Character> next = new ArrayList<>();
        for (int i = 0; i < str.size() - 1; i++) {
            if (str.get(i) == ch || str.get(i + 1) == ch) {
                next.add(ch);
            } else {
                next.add(str.get(i));
            }
        }
        return solve(next, ch) + 1;
    }
}