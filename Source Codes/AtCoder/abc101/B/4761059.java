import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = a;
    int ans = 0;
    while (a > 0) {
      ans += a % 10;
      a /= 10;
    }
    
    if(b % ans == 0){
      System.out.println("Yes");
    }
    else
      System.out.println("No");
  }
}