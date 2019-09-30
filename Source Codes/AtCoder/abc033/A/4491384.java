import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String pw = sc.next();

		String[] pass = pw.split("");
		String ans = "";

		if(pass[0].equals(pass[1]) && pass[1].equals(pass[2]) &&
		   pass[2].equals(pass[3])) {
			ans = "SAME";
		}else {
			ans = "DIFFERENT";
		}
		System.out.println(ans);
	}

}