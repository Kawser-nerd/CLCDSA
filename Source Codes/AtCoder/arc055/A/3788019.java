import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    String ans = "1";
    for(int i = 0; i < N; i++){
      if(i != N-1){
        ans += "0";
      }else if(i == N-1){
        ans += "7";
      }
    }
    System.out.println(ans);
  }
}