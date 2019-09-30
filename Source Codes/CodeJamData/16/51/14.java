package gcj.gcj2016.round3;

import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;

/**
 * Created by hama_du on 2016/06/10.
 */
public class A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int t = in.nextInt();
        for (int cs = 1 ; cs <= t ; cs++) {
            char[] c = in.next().toCharArray();

            out.println(String.format("Case #%d: %d", cs, solve(c)));
        }
        out.flush();
    }

    private static int solve(char[] mood) {
        int n = mood.length;
        int score = 0;
        int code = 0;
        int jam = 0;
        Stack<Character> stk = new Stack<>();
        for (int i = 0 ; i < n ; i++) {
            if (stk.size() == 0) {
                stk.push(mood[i]);
            } else {
                if (stk.peek() == mood[i]) {
                    stk.pop();
                    score += 10;
                } else {
                    int pool = stk.size();
                    int left = n - i;
                    if (pool + 1 <= left - 1) {
                        stk.push(mood[i]);
                    } else {
                        stk.pop();
                        score += 5;
                    }
                }
            }
        }
        return score;
    }
}
