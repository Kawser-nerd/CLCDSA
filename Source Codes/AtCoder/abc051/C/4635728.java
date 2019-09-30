import java.util.Scanner;

public class Main{

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int sx = scn.nextInt();
		int sy = scn.nextInt();
		int tx = scn.nextInt();
		int ty = scn.nextInt();
		int x = tx - sx;
		int y = ty - sy;
		for(int i = 0;i < x;i++) {
			System.out.print("R");
		}
		for(int i = 0;i < y;i++) {
			System.out.print("U");
		}
		for(int i = 0;i < x;i++) {
			System.out.print("L");
		}
		for(int i = 0;i < y;i++) {
			System.out.print("D");
		}
		System.out.print("D");
		for(int i = 0;i < x+1;i++) {
			System.out.print("R");
		}for(int i = 0;i < y+1;i++) {
			System.out.print("U");
		}
		System.out.print("L");
		System.out.print("U");
		for(int i = 0;i < x+1;i++) {
			System.out.print("L");
		}for(int i = 0;i < y+1;i++) {
			System.out.print("D");
		}
		System.out.print("R");
	}

}