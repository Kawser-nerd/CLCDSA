import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int W = sc.nextInt();
		int H = sc.nextInt();
		
		String s = "";
		for (int i = 0; i < H+2; i++) {
			s += "#";
		}
		
		System.out.println(s);
		for (int i = 0; i < W; i++) {
			System.out.println("#" + sc.next() + "#");
		}
		System.out.println(s);
	}
}