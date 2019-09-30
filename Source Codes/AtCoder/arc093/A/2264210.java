import java.util.Arrays;
import java.util.Scanner;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt()+2;
		int[]x=new int[n];
		for(int i=1;i<n-1;++i)
			x[i]=s.nextInt();

		int[]d=new int[n-1];
		for(int i=0;i<n-1;++i)
			d[i]=Math.abs(x[i+1]-x[i]);
		
		int dsum=Arrays.stream(d).sum();
		
		System.err.println(Arrays.toString(x));
		System.err.println(Arrays.toString(d));
		System.err.println(dsum);
		
		for(int i=1;i<n-1;++i)
			System.out.println(dsum-d[i-1]-d[i]+Math.abs(x[i+1]-x[i-1]));
	}
}