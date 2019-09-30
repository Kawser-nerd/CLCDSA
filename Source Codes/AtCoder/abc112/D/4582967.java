import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long m = sc.nextLong();
		for(long i=m/n; i>=1; i--){
			if(m%i==0){
				System.out.println(i);
				return;
			}
		}
	}
}