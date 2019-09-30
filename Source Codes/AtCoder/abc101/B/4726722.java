import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    System.out.println(n % digitSum(n) == 0 ? "Yes" : "No");
  }
  
  public static int digitSum(long n){
    int ans = 0;
    while(n != 0){
      ans += n % 10;
      n /= 10;
    }
    
    return ans;
  }
}