import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int c=scan.nextInt();
		int b=scan.nextInt();
		int a=scan.nextInt();
		int ans=a;
		for(;;) {
			if(ans%b==0&&ans%c==0&&ans>=a) {
				break;
			}
			ans++;
		}
		System.out.println(ans);
	}
}