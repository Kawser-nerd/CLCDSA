import java.util.Scanner;
public class Main{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String a=scan.next();
		String b=scan.next();
		String c=scan.next();
		System.out.println(String.valueOf(a.charAt(0)).toUpperCase()+""+String.valueOf(b.charAt(0)).toUpperCase()+""+String.valueOf(c.charAt(0)).toUpperCase());
		}
}