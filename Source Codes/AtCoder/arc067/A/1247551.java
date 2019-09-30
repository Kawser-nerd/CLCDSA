import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO ???????????????
		Scanner scan = new Scanner(System.in);
		int a = scan.nextInt();
		int an[] = new int[a+1];
		long ans=1;
		int c=0;
		int d = (int)Math.pow(10, 9)+7;
		for(int i=0;i<a+1;i++){
			an[i]=1;
		}
		for(int i=2;i<=a;i++){
			c=i;
			while(c%2 == 0){
				c/=2;
				an[2]++;
			}
			for(int n=3;n*n<=c;n+=2){
				while(c%n==0){
				c /= n;
				an[n]++;
				}
			}
			if(c>1){
				an[c]++;
			}
		}
		for(int i=0;i<an.length;i++){
			ans = (long)ans*an[i]%d;
		}
		System.out.println(ans);
 }
}