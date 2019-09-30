import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (System.in);
		  double rad=Math.abs((double)(sc.nextInt()%12)*30-(double)sc.nextInt()*(11.0/2));
		  System.out.println(Math.min(rad,360.0-rad));
	}
}