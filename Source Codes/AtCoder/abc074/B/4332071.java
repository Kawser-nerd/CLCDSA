import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int k = sc.nextInt();
    int sum = 0;
    for(int i = 0; i < n; i++){
      int x = sc.nextInt();
      sum += Math.min(x, k - x) * 2;
    }
    System.out.println(sum);
  }
}