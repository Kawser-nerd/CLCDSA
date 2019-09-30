import java.util.Scanner;

public class Main{
	public static void main(String args[])throws Exception{

		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		Boolean a = true;
		if(S.contains("N")) {
			if(S.contains("S")) {
				
			}else {
				a = false;
			}
		}
		if(S.contains("W")) {
			if(S.contains("E")) {
				
			}else {
				a = false;
			}
		}
		if(S.contains("S")) {
			if(S.contains("N")) {
				
			}else {
				a = false;
			}
		}
		if(S.contains("E")) {
			if(S.contains("W")) {
				
			}else {
				a = false;
			}
		}
		if(a) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}