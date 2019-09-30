import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input;
		input = sc.nextLine();
		String [] x = input.split("[ ]+");
		int n = Integer.parseInt(x[0]);
		int a = Integer.parseInt(x[1]);
		int b = Integer.parseInt(x[2]);
		if(n*a <= b) {
			System.out.println(n*a);
		}else {
			System.out.println(b);
		}
		sc.close();
	}
}