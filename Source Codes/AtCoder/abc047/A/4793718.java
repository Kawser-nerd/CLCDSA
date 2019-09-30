import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();

		if(a + b == c){
			System.out.println("Yes");
		}
		else if(b + c == a){
			System.out.println("Yes");
		}	
		else if(a + c == b){
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}