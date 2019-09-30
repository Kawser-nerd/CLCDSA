import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int x = scanner.nextInt();
    int y = scanner.nextInt();
    int k = scanner.nextInt();
    int ans = 0;
    if(k >= y){
      ans = x + 2 * y - k;
    }else{
      ans = x + k;
    }
    System.out.println(ans);
  }
}