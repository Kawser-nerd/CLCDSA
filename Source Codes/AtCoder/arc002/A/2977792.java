import java.util.Scanner;

public class Main {
	//private static Scanner stdIn;

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		int s = stdIn.nextInt();
		
		if(s%4 != 0)
			System.out.println("NO");
		else if(s%100 == 0 && s%400 != 0)
			System.out.println("NO");
		else if(s%100 == 0 && s%400 == 0)
			System.out.println("YES");
		else
			System.out.println("YES");
	}
}