import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		System.out.println(S.replace("O","0").replaceAll("D", "0").replaceAll("I", "1").replaceAll("Z", "2").replaceAll("S", "5").replaceAll("B", "8"));
	}
}