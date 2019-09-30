import java.util.Arrays;
import java.util.IntSummaryStatistics;
import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		int n=s.nextInt(),in[]=new int[n];
		for(int i=0;i<n;i++) in[i]=s.nextInt();
		IntSummaryStatistics iss=Arrays.stream(in).parallel().summaryStatistics();
		long max=iss.getMax(),sum=iss.getSum();

		System.out.println(sum);
		System.out.println(Math.max(0, max-(sum-max)));
	}
}