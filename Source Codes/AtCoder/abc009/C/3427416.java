import java.util.*;

public class Main {
    static String S;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        sc.nextLine();
        S = sc.nextLine();
        char[] c = S.toCharArray();
        Arrays.sort(c);

        String ans = "";

        for (int i = 0; i < N; i++) { // S????char?greedy??????
            for (int j = 0; j < N; j++) { // ??????c????????
                if (c[j] == '\0') continue;
                if (count(ans, c, c[j]) > K) continue;
                ans += c[j];
                c[j] = '\0';
                break;
            }
        }

        System.out.println(ans);
    }

    private static int count(String ans, char[] c, char ch) {
        int diff = 0;
        for (int i = 0; i < ans.length(); i++) {
            diff += S.charAt(i) == ans.charAt(i) ? 0 : 1;
        }

        if (ch != S.charAt(ans.length())) diff++;

        int[] a = new int[26];
        for (char b : c) {
            if (b == '\0') continue;
            a[b - 'a']++;
        }
        a[ch - 'a']--;

        for (int i = ans.length() + 1; i < S.length(); i++) {
            int idx = S.charAt(i) - 'a';
            if (a[idx] > 0) {
                a[idx]--;
            } else {
                diff++;
            }
        }

        return diff;
    }
}