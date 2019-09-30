import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int ax=sc.nextInt();
		int ay=sc.nextInt();
		int bx=sc.nextInt();
		int by=sc.nextInt();
		int cx=sc.nextInt();
		int cy=sc.nextInt();
		int a=bx-ax;
		int b=by-ay;
		int c=cx-ax;
		int d=cy-ay;
		System.out.println((double)Math.abs(a*d-b*c)/2);
	}
}