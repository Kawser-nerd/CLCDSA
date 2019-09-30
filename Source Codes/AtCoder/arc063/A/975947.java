import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String str = s.next();
    int count = 0;
    for (int i = 1; i < str.length(); i++) {
      if (str.charAt(i-1) != str.charAt(i)) {
        count++;
      }
    }
    System.out.println(count);
  }
}