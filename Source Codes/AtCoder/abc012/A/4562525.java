import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int x = sc.nextInt();
		int y = sc.nextInt();
		int temp = 0;
		
		temp = x;
		x = y;
		y = temp;
		System.out.println(x+" "+y);

	}

}