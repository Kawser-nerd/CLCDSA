import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);
	public static void main(String[] args) {
		String in=s.next();
		int a=s.nextInt(),b=s.nextInt(),c=s.nextInt(),d=s.nextInt();

		in=insert(in,d,"\"");
		in=insert(in,c,"\"");
		in=insert(in,b,"\"");
		in=insert(in,a,"\"");

		System.out.println(in);
	}
	private static String insert(String in, int a, String s) {
		return in.substring(0, a)+s+in.substring(a);
	}
}