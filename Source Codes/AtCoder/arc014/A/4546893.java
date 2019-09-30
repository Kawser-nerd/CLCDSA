import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		String ans = "";
		if(n%2==0) {
			ans = "Blue";
		}else {
			ans = "Red";
		}

		System.out.println(ans);
	}
}