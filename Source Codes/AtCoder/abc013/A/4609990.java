import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String[] words = {"A", "B", "C", "D", "E"};
		for (int i = 0; i < 5; i++) {
			if (x.equals(words[i])) {
				System.out.println(i + 1);
			}
		}
	}
}