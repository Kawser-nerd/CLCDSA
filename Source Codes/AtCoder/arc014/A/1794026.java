import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		if(N % 2 == 0){
			System.out.println("Blue");
		}else{
			System.out.println("Red");
		}
	}
}