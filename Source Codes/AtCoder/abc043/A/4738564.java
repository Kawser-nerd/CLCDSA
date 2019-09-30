import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int c_number = 0;
		for(int i = 1; i <= n; i++){
			c_number = c_number + i;
		}
		System.out.println(c_number);
	}
}