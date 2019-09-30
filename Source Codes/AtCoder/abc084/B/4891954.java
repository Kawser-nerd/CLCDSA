import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    String S = sc.next();

    for (int i = 0; i < a; i++) {
      if (S.charAt(i) < '0' || S.charAt(i) > '9') {
        System.out.println("No");
        return;
      }
    }
    for (int i = a + 1; i < a + b + 1; i++) {
      if (S.charAt(i) < '0' || S.charAt(i) > '9') {
        System.out.println("No");
        return;
      }
    }
    if(S.charAt(a) != '-'){
      System.out.println("No");
      return;
    }
    System.out.println("Yes");
  }
}