import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int d = sc.nextInt();
    int x = sc.nextInt();
    for(int i = 0; i < n; i++){
      int a = sc.nextInt();
      for(int j = 1; j <= d; j += a){
        x++;
      }
    }
    System.out.println(x);
  }
}