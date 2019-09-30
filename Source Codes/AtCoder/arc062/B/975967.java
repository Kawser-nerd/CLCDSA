import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String input = s.next();
    int score = 0;
    for (int i = 0; i < input.length(); i++) {
      char c = input.charAt(i);
      if (c == 'g' && i % 2 == 1) {
        score++;
      } else if (c == 'p' && i % 2 == 0) {
        score--;
      }
    }
    System.out.println(score);
  }
}