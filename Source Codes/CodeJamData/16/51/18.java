import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.Stack;

public class TeachingAssistant {

    public static void main(String[] args) throws FileNotFoundException {
//        Scanner cin = new Scanner(new File("A-small-attempt0.in"));
//        PrintStream cout = new PrintStream("A-small-attempt0.out");
        Scanner cin = new Scanner(new File("A-large.in"));
        PrintStream cout = new PrintStream("A-large.out");
//        Scanner cin = new Scanner(System.in);
//        PrintStream cout = System.out;

        int _case = 0;
        for (int T = cin.nextInt(); T > 0; T--) {
            _case++;
            StringBuilder ans = new StringBuilder();

            String s = cin.next();
            int totalRequested = 0;
            Stack<Character> stack = new Stack<>();
            Stack<Integer> points = new Stack<>();
            int maxPoints = 0;
            int cnt = 0;
            for (int i = 0; i < s.length(); i++) {
                if (!stack.empty() && stack.peek() == s.charAt(i) || totalRequested == s.length() / 2) {
                    maxPoints += stack.pop() == s.charAt(i) ? points.pop() : points.pop() - 5;
                } else {
                    stack.push(s.charAt(i));
                    points.push(10);
                    totalRequested++;
                }
            }
            ans.append(maxPoints);

            cout.printf("Case #%d: %s%n", _case, ans.toString());
        }

        cin.close();
        cout.close();
    }
}
