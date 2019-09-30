import java.util.Scanner;
public class Main {
	static int N;
	static String s;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N=sc.nextInt();
		s=N==25?"Christmas":N==24?"Christmas Eve":N==23?"Christmas Eve Eve":"Christmas Eve Eve Eve";
		System.out.println(s);
	}
}