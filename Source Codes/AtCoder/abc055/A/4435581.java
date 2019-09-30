import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int sum = 0;
    for(int i = 1;i <= n;i++){
      sum = sum + 800;
      if(i%15 == 0){
        sum = sum - 200;
      }
    }
    System.out.println(sum);
  }
}