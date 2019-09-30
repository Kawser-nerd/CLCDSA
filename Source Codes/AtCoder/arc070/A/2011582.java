import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int n=sc.nextInt();
		int k=(int) Math.sqrt(2*n);
		while(true){
			int sum=(1+k)*k/2;
			if(sum<n)
				++k;
			else
				break;
		}
		System.out.println(k);
	}
}