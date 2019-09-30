import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            String s = scanner.next();
            Stack<Boolean> stack = new Stack<>();
            int removed = 0;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                stack.push(c != '0');
                while(stack.size() > 1) {
                    boolean top = stack.pop();
                    boolean second = stack.pop();
                    if (top != second) {
                        removed+=2;
                    } else {
                        stack.push(second);
                        stack.push(top);
                        break;
                    }
                }
            }
            System.out.println(removed);
        }
    }
}