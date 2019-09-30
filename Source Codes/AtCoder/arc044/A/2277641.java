import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int wantUpper = n;
 
		boolean isP = true;
		for(int i = 2; i <= Math.sqrt(wantUpper); i++) {
			if(n%i==0) {
				isP = false;
				break;
			}
		}
		if(n!=1 && isP) {
			System.out.println("Prime");
		} else {
			String s = String.valueOf(n);
			int a = Integer.parseInt(s.substring(s.length()-1));
			long sum = 0;
			for(char c : s.toCharArray()) {
				sum += Integer.parseInt(String.valueOf(c));
			}
			if(n!=1&&a!=5&&sum%3!=0&&a%2!=0) {
				System.out.println("Prime");
			} else {
				System.out.println("Not Prime");
			}
		}
	}
}