import java.util.Scanner;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt(),min=100;
		for(int i=0;i<n;i++) {
			min=Math.min(min,sc.nextInt());
		}
		System.out.println(min);
	}
}