import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int[]d=new int[7],j=new int[7];
		int sum=0;
		for(int i=0;i<7;i++)
			d[i]=s.nextInt();
		for(int i=0;i<7;i++)
			j[i]=s.nextInt();
		for(int i=0;i<7;i++)
			sum+=Math.max(d[i],j[i]);
		System.out.println(sum);
	}
}