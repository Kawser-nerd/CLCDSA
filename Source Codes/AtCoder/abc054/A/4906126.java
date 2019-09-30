import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		int a = scan.nextInt();
		if(a == 1){
			a = 100;
		}
		int b = scan.nextInt();
		if(b == 1){
			b = 100;
		}

		if(a > b){
			System.out.println("Alice");
		}
		else if(a < b){
			System.out.println("Bob");
		}
		else{
			System.out.println("Draw");
		}
	}
}