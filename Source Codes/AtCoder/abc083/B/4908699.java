import java.util.*;
public class Main{
	public static void main(String[]args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int a=sc.nextInt();
		int b=sc.nextInt();
		int ans=0;
		for(int i=0;i<=n;i++) {
			int ds=digitSum(i);
			if(a<=ds&&ds<=b)ans+=i;
		}
		System.out.println(ans);
	}
	static int digitSum(int i) {
		if(i==0)return 0;
		return i%10+digitSum(i/10);
	}
}