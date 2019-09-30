import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    if(N%(A+B) != 0 &&  N-(N/(A+B))*(A+B) <= A){
      System.out.println("Ant");
    }else if(N%(A+B) != 0 &&  N-(N/(A+B))*(A+B) > A){
      System.out.println("Bug");
	  }else if(N%(A+B) == 0){
      System.out.println("Bug");
    }
  }
}