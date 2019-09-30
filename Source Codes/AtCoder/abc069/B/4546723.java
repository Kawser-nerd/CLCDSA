import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		int count = 0;

		String t = s.substring(1,s.length()-1);
		count = t.length();

		System.out.println(s.substring(0,1)+count+s.substring(s.length()-1,s.length()));
	}
}