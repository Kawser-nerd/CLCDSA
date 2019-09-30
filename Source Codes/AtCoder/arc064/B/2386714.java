import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		System.out.println(str.charAt(0)==str.charAt(str.length()-1) ^ str.length()%2==1 ? "First" : "Second");
	}

}