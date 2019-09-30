import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	public void _main(String[] args) {
		Scanner sc = new Scanner(in);
		int n = sc.nextInt();

		if(n==1) {
			out.println("Hello World");
		}else {
			int a = sc.nextInt();
			int b = sc.nextInt();
			out.println(a+b);
		}

		sc.close();
	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}