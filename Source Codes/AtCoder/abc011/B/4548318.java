import java.util.Scanner;

class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String name = sc.next();
		String lname = name.toLowerCase();
		String tname = lname.substring(0,1);
		String uname=tname.toUpperCase();
		String ans = uname+lname.substring(1,name.length());
		System.out.println(ans);
	}
}