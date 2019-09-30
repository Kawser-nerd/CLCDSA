import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		for(int t=sc.nextInt();t>0;t--){
			long a=sc.nextLong(),b=sc.nextLong(),c=sc.nextLong(),d=sc.nextLong();
			if(a<b || d<b){
				pl("No");
				continue;
			}
			if(c>=b){
				pl("Yes");
				continue;
			}
			long g=gcd(b,d);
			a%=b;
			long max=g*((b-a)/g)+a;
			if(max>=b)max-=g;
			if(max>c)pl("No");
			else pl("Yes");
		}
	}
	static void pl(Object o){System.out.println(o);}
	static long gcd(long a,long b){
		if(a<b)b%=a;
		while(b>0){
			a%=b;
			if(a==0)return b;
			b%=a;
		}
		return a;
	}
}