import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int a=scan.nextInt();
		int b=scan.nextInt();
		if(a==2||b==2) {
			System.out.println("No");
			return;
		}
		if(a==1) {
			if(b==3||b==5||b==7||b==8||b==10||b==12) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		if(a==3) {
			if(b==5||b==7||b==8||b==10||b==12) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		if(a==4) {
			if(b==6||b==9||b==11) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		if(a==5) {
			if(b==7||b==8||b==10||b==12) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		if(a==6) {
			if(b==9||b==11) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		if(a==7) {
			if(b==8||b==10||b==12) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		if(a==8) {
			if(b==10||b==12) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
		if(a==9) {
		if(b==11) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
		}
		if(a==10) {
			if(b==12) {
			System.out.println("Yes");
		}
			else {
				System.out.println("No");
			}
		}
		if(a==11) {
			System.out.println("No");
		}
		if(a==12) {
			System.out.println("No");
		}
	}
}