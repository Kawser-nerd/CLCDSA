import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt();
		if(N==1) {
			System.out.println("Hello World");
		}else {
			System.out.println(scn.nextInt() + scn.nextInt());
		}
	}

}