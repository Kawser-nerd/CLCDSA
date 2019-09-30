import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int buf=n/10;
		n-=(buf*10);
		int ans=buf*100;
		System.out.println(ans+((n>6)?100:n*15));
	}

}