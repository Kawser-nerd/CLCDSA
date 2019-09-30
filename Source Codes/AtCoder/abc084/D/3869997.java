import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int Q = scanner.nextInt();
    int[] count = new int[100001];
    for(int i = 2; i <= 100000; i++){
      if(isPrime(i) == true && isPrime((i+1)/2) == true){
        count[i] = count[i-1] + 1;
      }else{
        count[i] = count[i-1];
      }
    }
    for(int i = 0; i < Q; i++){
      int l = scanner.nextInt();
      int r = scanner.nextInt();
      System.out.println(count[r]-count[l-1]);
    }

  }
  public static boolean isPrime(int n){
    if(n == 1) return false;
    if(n == 2) return true;
    for(int i = 2; i <= Math.sqrt(n); i++){
      if(n % i == 0){
        return false;
      }
    }
    return true;
  }
}