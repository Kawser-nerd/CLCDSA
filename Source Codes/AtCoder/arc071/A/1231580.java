import java.util.Scanner;

public class Main {

    private static int[] mins = new int[26];

    public static void solve(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            mins[i] = Math.min(mins[i], cnt[i]);
        }
    }

    public static void main(String[] args) {
        for (int i = 0; i < 26; i++) {
            mins[i] = Integer.MAX_VALUE;
        }

        Scanner sc = new Scanner(System.in);
        int n = Integer.valueOf(sc.nextLine());
        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            solve(s);
        }

        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            for (int k = 0; k < mins[i]; k++) {
                builder.append((char) (i + 'a'));
            }
        }
        System.out.println(builder.toString());
    }
}