import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO ???????????????

		Scanner scanner = new Scanner(System.in);
		String string = scanner.next();

		int num[] = new int[30];
		Arrays.fill(num, 0);
		for(int i = 0; i < string.length(); i++) {
			char c = string.charAt(i);
			num[c - 'a']++;
		}

		String res = "None";
		for(int i = 0; i < 26; i++) {
			if(num[i] == 0) {
				char c = (char)(i + 'a');
				res = String.valueOf(c);
				break;
			}
		}

		System.out.println(res);
	}

}