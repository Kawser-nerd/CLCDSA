import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        int[] start = new int[26];
        int[] goal = new int[26];
        boolean isAns = true;

        for (int i = 0; i < 26; i++) {
            start[i] = -1;
            goal[i] = -1;
        }

        for (int i = 0; i < s.length; i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            if (start[a] != -1 || goal[b] != -1) {
                if (start[a] != b || goal[b] != a) {
                    isAns = false;
                    break;
                }
            }
            start[a] = b;
            goal[b] = a;
        }

        System.out.println(isAns ? "Yes" : "No");
    }
}