import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String X = sc.next();
    Deque<Character> stack = new ArrayDeque<>(); // ????
    for (int i = 0; i < X.length(); i++) {
      if (X.charAt(i) == 'S') { // i???S
        stack.push(X.charAt(i));
      } else { // i???T
        if (stack.size() == 0) { // ??????
          stack.push(X.charAt(i));
        } else if (stack.peek() == 'S') { // i-1???S
          stack.pop();
        } else if (stack.peek() == 'T') { // i-1???T
          stack.push(X.charAt(i));
        }
      }
    }
    System.out.println(stack.size());
  }
}