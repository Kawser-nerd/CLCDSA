import java.util.Scanner;
import java.util.Arrays;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    if(A < 0 && B >0){
      System.out.println(B-A-1);
    }else{
      System.out.println(B-A);
    }
  }
}