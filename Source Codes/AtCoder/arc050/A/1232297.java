import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		System.out.println(Character.toLowerCase(s.next().charAt(0))==s.next().charAt(0)
				?"Yes":"No");
	}
}