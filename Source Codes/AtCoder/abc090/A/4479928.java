import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		for(int i = 0; i < 3; ++i) {
			String line = in.nextLine();
			System.out.print(line.charAt(i));
		}
		in.close();
		System.out.println("");
	}

}