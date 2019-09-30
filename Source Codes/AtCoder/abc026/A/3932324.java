import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int A = sc.nextInt();
		
		int x = A / 2;
		int y = A / 2 + A % 2;
		System.out.println(x * y);
	}
}