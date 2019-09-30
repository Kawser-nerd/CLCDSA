import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int b = scan.nextInt();
		int c = scan.nextInt();

		if(a == b && b == c){
			System.out.println("1");
		}
		else if(a == b && a != c){
			System.out.println("2");
		}
		else if(b == c && b != a){
			System.out.println("2");
		}
		else if(a == c && c != b){
			System.out.println("2");
		}
		else {
			System.out.println("3");
		}
	}
}