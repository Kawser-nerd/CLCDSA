import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String input = s.next();
    int a = s.nextInt();
    int b = s.nextInt();
    int c = s.nextInt();
    int d = s.nextInt();
    for (int i = 0; i < input.length(); i++) {
      if (i == a || i == b || i == c || i == d) {
        System.out.print("\"");
      }
      System.out.print(input.charAt(i));
    }
    if (input.length() == d) {
      System.out.print("\"");
    }
    System.out.println();
  }
}