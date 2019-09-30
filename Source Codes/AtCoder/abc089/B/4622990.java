import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int ans = 0;
		boolean G = false,W = false,P = false,Y = false;
		for(int i = 0;i < n;i++) {
			String s = sc.next();
			if(s.equals("G") && !G) {G = true; ans++;}
			if(s.equals("P") && !P) {P = true; ans++;}
			if(s.equals("W") && !W) {W = true; ans++;}
			if(s.equals("Y") && !Y) {Y = true; ans++;}
		}
		if(ans == 3) System.out.println("Three");
		else if(ans == 4) System.out.println("Four");
	}
}