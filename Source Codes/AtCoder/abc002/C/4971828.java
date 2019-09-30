import java.util.Scanner;

public class Main {
	private static Scanner sc = new Scanner(System.in);
	
	public static void main(String args[]) {
		
		
		double x1=sc.nextInt(),y1=sc.nextInt(),x2=sc.nextInt(),y2=sc.nextInt(),x3=sc.nextInt(),y3=sc.nextInt();
		
		
		double aaa=Math.abs(((x1-x3)*(y2-y3))-((x2-x3)*(y1-y3)));
		
		System.out.println(aaa/2);
	}
}