import java.util.Scanner;

public class Main {
    private static long calc(String s, boolean[] ifplus, int i) {
        if(i == s.length() - 1) {
            long ans = 0;
            int before = -1;
            for(int j = 0; j < s.length() - 1; j++) {
                if(ifplus[j]) {
                    ans += Long.parseLong(s.substring(before + 1, j + 1));
                    before = j;
                }
            }
            ans += Long.parseLong(s.substring(before + 1));
            return ans;
        }

        boolean[] next1 = new boolean[s.length() - 1];
        boolean[] next2 = new boolean[s.length() - 1];
        for(int j = 0; j < i; j++) {
            next1[j] = ifplus[j];
            next2[j] = ifplus[j];
        }
        next1[i] = true;
        next2[i] = false;
        return calc(s, next1, i + 1) + calc(s, next2, i + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        boolean[] tmp = new boolean[s.length() - 1];
        System.out.println(calc(s, tmp, 0));

        sc.close();
    }
}