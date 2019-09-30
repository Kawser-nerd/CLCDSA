import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] s = sc.next().toCharArray();

        int c = 'a';
        int[] cnt = new int[26];
        for (int i = 0; i < s.length; i++) {
            cnt[s[i] - c]++;
        }
        
        boolean ans = true;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0 && cnt[i] % 2 == 1)
                ans = false;
        }

        System.out.println(ans ? "Yes" : "No");
    }
}