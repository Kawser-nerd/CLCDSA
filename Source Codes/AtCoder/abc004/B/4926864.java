import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] lines = new String[4];
		StringBuilder builder = new StringBuilder(7);
		for(int i = 3; i >= 0; i--) {
			lines[i] = builder.append(sc.nextLine()).reverse().toString();
			builder.setLength(0);
		}
		for(int i = 0; i < 4; i++)
			System.out.println(lines[i]);
	}

}