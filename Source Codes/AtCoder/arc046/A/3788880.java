import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    String ans = "";
    if(N%9 != 0){
      for(int i = 0; i < N/9+1; i++){
        ans += N % 9;
      }
    }else{
      for(int i = 0; i < N/9; i++){
        ans += 9;
      }
    }
    System.out.println(ans);
  }
}