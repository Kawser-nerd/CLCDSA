import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    if(N >= 5){
      System.out.println((N-5)*A + 5*B);
    }else{
      System.out.println(N*B);
    }
  }  
}