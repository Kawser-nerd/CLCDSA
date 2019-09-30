import java.util.Scanner;
import java.util.Arrays;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int[] num = new int[56000];
    for(int i = 3; i <= 55555; i++){
      if(search(i)){
        num[i] = i;
      }
    }
    int count = N;
    for(int i = 3; i <= 55555; i++){
      if(num[i] != 0 && count > 0){
        count--;
        System.out.println(num[i]);
      }
    }
  }
  public static boolean search(int n){
    if(n == 1 || n == 2){
      return false;
    }
    for(int i = 2; i <= Math.sqrt(n); i++){
      if(n % i == 0 || n % 10 != 3){
        return false;
      }
    }
    return true;
  }
}