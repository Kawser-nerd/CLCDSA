import java.util.Scanner;
public class Main {
	static long N;
	static long ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int call=0;
		int cut=0;
		int n=sc.nextInt();
		for(int i=0;i<n;i++) {
			int a=sc.nextInt();
			for(;;) {
				if(a%2!=0&&a%3!=2)break;
				a--;
				cut++;
			}
		}
System.out.println(cut);
	}
}