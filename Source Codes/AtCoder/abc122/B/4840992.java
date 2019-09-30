import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		
		String x = "";
		int num1 = 0;
		int num2 = 0;
		
		for(int i = 0; i < S.length(); i++) {
			if((S.charAt(i) == 'A') || (S.charAt(i) == 'T') || (S.charAt(i) == 'G') || (S.charAt(i) == 'C')) {
				x += "a";
			} else {
				x += "b";
			}
		}
		
		for(int i = 0; i < S.length(); i++) {
			if(x.charAt(i) == 'a') {
				num1++;
				if(i == (S.length() - 1)) {
					if(num2 < num1) {
						num2 = num1;
					}
				}
			} else {
				if(num2 < num1) {
					num2 = num1;
				}
				num1 = 0;
			}
		}
		
		System.out.println(num2);
		
	}
}