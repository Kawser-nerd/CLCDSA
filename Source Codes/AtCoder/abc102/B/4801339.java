import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int max=1,min=1000000000;
		int j=sc.nextInt();
		for(int i=0;i<j;i++) {
			int a=sc.nextInt();
			max=Math.max(max, a);
			min=Math.min(min, a);
		}
		System.out.println(max-min);
	}
}