import java.util.Scanner;

public class Main{
	public static void main(String args[]){
		Scanner scan = new Scanner(System.in);

		String str = scan.next();
		char[] c = str.toCharArray();
		c[5] = ' ';
		c[13] = ' ';
		str = new String(c);
		System.out.println(str);
	}
}