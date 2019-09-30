import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int ans = 1;
    while(ans <= n){
      ans *= 2;
    }
    System.out.println(ans/2);
  }
}