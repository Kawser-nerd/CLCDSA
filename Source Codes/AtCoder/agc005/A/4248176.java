import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        Stack<String> stack = new Stack<>();
        for (int i = 0 ; i < S.length() ; i++) {
            if (S.substring(i, i + 1).equals("S")) {
                stack.push("S");
            } else {
                if (stack.empty() || stack.peek().equals("T")) {
                    stack.push("T");
                } else {
                    stack.pop();
                }
            }
        }
        System.out.println(stack.size());
    }

}