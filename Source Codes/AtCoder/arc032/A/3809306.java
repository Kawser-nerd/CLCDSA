import java.util.*;

public class Main {
  public static void main(String args[]){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int sum = 0;
    for(int i = 1; i <= N; i++){
      sum += i;
    }
    boolean flag = true;
    if(N == 1){
      flag = false;
    }else if(N == 2){
      flag = true;
    }else if(N > 2){
      for(int i = 2; i <= Math.sqrt(sum); i++){
        if(sum % i == 0){
          flag = false;
          break;
        }
      }
    }
    if(flag){
      System.out.println("WANWAN");
    }else{
      System.out.println("BOWWOW");
    }
  }
}