import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String a = sc.next();
    System.out.println(sc.next().replaceAll(a, ""));
  }
}