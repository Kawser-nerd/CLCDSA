import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		char[]in=s.next().toCharArray();
		for(int i=in.length/2;i>=0;i--) {
			if(in[in.length-i-1]!=in[i]) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}