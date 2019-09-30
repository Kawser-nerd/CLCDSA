import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();
    int ans;
    if(a <= c){
      if(d <= b){
        ans = d - c;
      }else{
        ans = b - c;
      }
    }else{
      if(d <= b){
        ans = d - a;
      }else{
        ans = b - a;
      }
    }
    System.out.println(Math.max(ans, 0));
  }
}