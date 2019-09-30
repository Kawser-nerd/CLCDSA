import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String n1=sc.next();
		String n2=sc.next();
		if((n1.charAt(0)*1-n2.charAt(0)*1)==-32) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}