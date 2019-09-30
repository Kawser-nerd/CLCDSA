import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
	static int c[];
	static int n;
	static int lowbit(int x){
		return x&(-x);
	}
	static void add(int i,int val){
		while(i<=n){
			c[i]+=val;
			i+=lowbit(i);
		}
	}
	static int sum(int i){
		int sum=0;
		while(i>0){
			sum+=c[i];
			i-=lowbit(i);
		}
		return sum;
	}
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		n=in.nextInt(); int p=in.nextInt();c=new int[n];
//		c=new int[n+1];
//		int a[]=new int[n+1];
//		for(int i=1;i<=n;i++){
//			a[i]=i;
//		}
//		for(int i=1;i<=n;i++){
//			add(i,a[i]-a[i-1]);
//		}
		while(p-->0){
			int l=in.nextInt();
			int r=in.nextInt();
			int k=in.nextInt();
			Arrays.fill(c, l-1, r, k);
			
		}
		for(int i:c){
			System.out.println(i);
		}
		
	}
}