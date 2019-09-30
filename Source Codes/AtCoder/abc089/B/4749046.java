import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String input[] = new String[n];
		int yellow = 0;
		for(int i= 0;i < n;i++) {
			input[i] = sc.next();
			if(input[i].equals("Y"))yellow++;
		}
		if(yellow > 0) {
			System.out.println("Four");
		}else System.out.println("Three");
		sc.close();
	}
}