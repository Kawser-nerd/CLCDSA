import java.util.Scanner;

class Main{
	public static  void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int k = sc.nextInt();
		int i=k,sum=k,recy;
		while(i>=n){
			recy = i/n;
			i += recy*m-recy*n;
			sum+=recy*m;
		}
		System.out.println(sum);
	}
}