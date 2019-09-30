import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
public class Main {
    static long MOD = 1000000007;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s1 = sc.next();
        String s2 = sc.next();
        String ans = "";
        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) == s2.charAt(i)) {
                ans += "x";
            } else {
                ans += "y";
                i++;
            }
        }
        long res = 1;
        if (ans.charAt(0) == 'x') {
            res *= 3;
        } else {
            res *= 6;
        }
        for (int i = 1; i < ans.length(); i++) {
            if (ans.charAt(i - 1) == 'x' && ans.charAt(i) == 'x') {
                res *= 2;
            } else if (ans.charAt(i - 1) == 'x' && ans.charAt(i) == 'y') {
                res *= 2;
            } else if (ans.charAt(i - 1) == 'y' && ans.charAt(i) == 'x') {
                res *= 1;
            } else if (ans.charAt(i - 1) == 'y' && ans.charAt(i) == 'y') {
                res *= 3;
            }
            res %= MOD;
        }
        System.out.println(res);
    }
}