import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		double x = 0;
		int y = 0;

		if(n-m>0){
			y = (n-m)*100;
		}
		double k = Math.pow(2, m);

		double p,q;
		p=1-1/k;
		for(int i=1; i<3500000; i++){
			q=Math.pow(p, i-1);
			x += (y + 1900*m)*i*q/(double)k;
		}
		System.out.println(Math.round(x));
		sc.close();

	}
}