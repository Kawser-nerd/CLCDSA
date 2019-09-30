import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int x = sc.nextInt();
    int min = 1000;
    int sum = 0;
    
    for(int i = 0; i < n; i++){
      int num = sc.nextInt();
      min = Math.min(min, num);
      sum += num;
    }
    System.out.println(n + (x - sum)/min);
  }
}