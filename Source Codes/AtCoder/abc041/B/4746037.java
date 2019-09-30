import java.util.Scanner;
 
class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long a=sc.nextLong(),b=sc.nextLong(),c=sc.nextLong();
		System.out.println(a*b%1000000007*c%1000000007);
	}
}