import java.util.Arrays;
import java.util.Scanner;
public class Main{
	static long m;
	public static void main(String[] args)throws Exception{
		new Main().solve();
	}
	
	void solve(){
		Scanner sc=new Scanner(System.in);
		long a=sc.nextLong();
		long b=sc.nextLong();
		
		m=sc.nextLong();
		long[][] mt1={{10%m,1},{0,1}};
		long oneA=mxVector(mxNthPow(mt1,a),new long[][]{{0},{1}})[0][0];
		long gcd=GCD(a,b);
		long d=b/gcd;
		long[][] mt2={{pow(10,gcd),1},{0,1}};
		long oneF=mxVector(mxNthPow(mt2,d),new long[][]{{0},{1}})[0][0];
		System.out.println((oneA*oneF)%m);
	}
	long LCM(long a,long b){
		long gcd=GCD(a,b);
		long resA=a/gcd;
		long resB=b/gcd;
		return gcd*resA*resB;
	}
	
	long GCD(long a,long b){
		if(b>a){
			long d=a;
			a=b;
			b=d;
		}
		if(b==0)return a;
		return GCD(b,a%b);
	}
	//A*B
	long[][] mxProduct(long[][] a,long[][] b){
		long[][] result=new long[a.length][a.length];
		
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a.length;j++){
				for(int k=0;k<a.length;k++){
					result[i][j]+=(a[i][k]*b[k][j])%m;
					result[i][j]%=m;
				}
			}
		}
		return result;
	}
	//A^2
	long[][] mx2thPow(long[][] a){
		return mxProduct(a,a);
	}
	
	long[][] mxNthPow(long[][] a,long n){
		long[][] ans={{1,0},{0,1}};
		long[][] aa=a;
		while(n>0){
			if(n%2==0){
				aa=mx2thPow(aa);
				n/=2;
			}else if(n%2==1){
				ans=mxProduct(aa,ans);
				n--;
			}
//			System.err.println(Arrays.deepToString(aa));
		}
//		System.err.println(Arrays.deepToString(ans));
		return ans;
	}
	
	//A*v
	long[][] mxVector(long[][] a,long[][] v){
		long[][] ans=new long[2][1];	
//		System.err.println(Arrays.deepToString(a));
//		System.err.println(Arrays.deepToString(v));
		for(int i=0;i<a[0].length;i++){
			for(int j=0;j<a.length;j++){
				ans[i][0]+=(a[i][j]*v[j][0])%m;
			}
		}
//		System.err.println(Arrays.deepToString(ans));
		return ans;
	}
	long pow(long a,long n){
		long ans=1;
		long aa=a;
		while(n>=1){
			if(n%2==0){
				aa*=aa;
				aa%=m;
				n/=2;
			}else if(n%2==1){
				ans*=aa;
				ans%=m;
				n--;
			}
		}
		return ans;
	}
	void tr(Object...objects){System.err.println(Arrays.deepToString(objects));}
}