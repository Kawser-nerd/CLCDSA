import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String line = scanner.nextLine();
    Stack<Character> items = new Stack<>();
    for (char letter : line.toCharArray()) {
      if (Character.isDigit(letter)) {
        items.push(letter);
      } else if (letter == 'B' && !items.isEmpty()) {
         items.pop();
      }
    }
    
    StringBuilder builder = new StringBuilder();
    for (char letter : items) {
      builder.append(letter); 
    }
    
    System.out.println(builder);
  }
}