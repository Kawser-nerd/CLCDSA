import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		long[] c = new long[a];
		long ans = 0;
		for(int i = 0; i<a ;i++){
			c[i]=sc.nextLong();
		}
		for(int i = 0; i<a-b+1; i++){
			for(int j = i; j<i+b;j++){
				ans+=c[j];
			}
		}
		System.out.println(ans);
	}
}