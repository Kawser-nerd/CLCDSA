import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		long[] fibonacci=new long[42];
		fibonacci[1]=1;
		fibonacci[2]=1;
		for(int i=3; i<=41; i++) {
			fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
		}
		int a=sc.nextInt();
		System.out.println(fibonacci[a]+" "+fibonacci[a+1]);
	}
}