import java.util.*;
import java.math.*;

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String input = s.next();
    System.out.println(input.replaceAll("[a-zA-Z]", ""));
  }
}