import java.util.Scanner;
 class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int buf=0;
		for(int i=0;i<n;i++){
			buf+=(sc.nextInt()*sc.nextInt());
		}
		System.out.println((buf*105)/100);
	}
}