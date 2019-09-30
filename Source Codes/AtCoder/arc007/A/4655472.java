import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String x = sc.next();
		String[] input = sc.next().split("");
		StringBuffer ans = new StringBuffer();

		for(int i=0; i<input.length; i++) {
			if(!input[i].equals(x)) {
				ans.append(input[i]);
			}
		}
		System.out.println(ans);
	}

}