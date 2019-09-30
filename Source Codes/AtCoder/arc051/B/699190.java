import java.util.Scanner;


public class Main {
	public static int count=0;
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int a = 2; 
		int b = 1;
		int c;
		for (int i = 1; i < k; i++){
			c = a;
			a = a + b;
			b = c;
		}
		System.out.println(a + " " + b);
	}

}