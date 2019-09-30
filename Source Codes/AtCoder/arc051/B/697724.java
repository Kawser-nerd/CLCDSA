import java.util.Scanner;
public class Main{
	public static void main(String[] args)throws Exception{
		new Main().solve();
	}
	void solve(){
		Scanner sc=new Scanner(System.in);
		long k=sc.nextLong();
		for(long aa=1;;aa++){
			long a=aa;
			long b=0;
			for(int i=0;i<k;i++){
				if(a<b){
					long d=a;
					a=b;
					b=d;
				}
				long nextA;
				long nextB=a;

				//nextA>nextB

				//nextA=a+b;
				//nextB=a;

				nextA=a+b;
				a=nextA;
				b=nextB;
			}
			if(1000000000>a||1000000000>b){
				System.out.println(b+" "+a);
//				gcd(a,b);
//				System.out.println(k);
				return;
			}

		}
	}
	static int count=0;
	long gcd(long a,long b){
		if(a>b){
			long d=a;
			a=b;
			b=d;
		}
		if(a==0)return b;
		else{ 
			count++;
			return gcd(a,b%a);

		}
	}
}