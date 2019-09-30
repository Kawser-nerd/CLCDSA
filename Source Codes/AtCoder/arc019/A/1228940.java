import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.println(Integer.parseInt(
				s.next()
				.replace('O','0')
				.replace('D','0')
				.replace('I','1')
				.replace('Z','2')
				.replace('S','5')
				.replace('B','8')
				));
	}
}