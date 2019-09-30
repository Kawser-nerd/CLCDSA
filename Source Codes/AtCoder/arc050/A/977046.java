import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    char upper = s.next().charAt(0);
    char lower = s.next().charAt(0);
    System.out.println(upper - 'A' == lower - 'a' ? "Yes" : "No");
  }
}