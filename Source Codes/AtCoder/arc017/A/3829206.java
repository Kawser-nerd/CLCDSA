import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    if(isPrime(N) == true){
      System.out.println("YES");
    }else{
      System.out.println("NO");
    }
  }
  public static boolean isPrime(int n){
    if(n == 1){
      return false;
    }
    for(int i = 2; i <= Math.sqrt(n); i++){
      if(n % i == 0){
        return false;
      }
    }
    return true;
  }
}