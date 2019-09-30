import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    String ans = "Red";
    if(N % 2 == 0) ans = "Blue";
    System.out.println(ans);
  }
}