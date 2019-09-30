import java.util.Scanner;

public class Main {
	static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {
		double res=-1145141919;
		for(int n=s.nextInt();n>0;n--) {
			double sum=0;
			for(int j=0;j<4;j++)
				sum+=s.nextInt();
			sum+=s.nextInt()*110/900.0;

			res=Math.max(res, sum);
		}
		System.out.println(res);
	}
}