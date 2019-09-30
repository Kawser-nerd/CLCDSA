import java.util.Scanner;

public class Main{
	static long a,b,m;
	static long[][] pow(long x,long[][] a){
		if(x==1) return a;
		else if(x==0){
			long[][] res={{1,0},{0,1}};
			return res;
		}
		else if(x%2==0) return pow(x/2,mul(a));
		else return mul(a,pow(x/2,mul(a)));
	}
	static long[][] mul(long[][] a){
		long[][] res=new long[2][2];
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					res[i][j]+=(a[i][k]*a[k][j])%m;
					res[i][j]%=m;
				}
			}
		}
		return res;
	}
	static long[][] mul(long[][] a,long[][] b){
		long[][] res=new long[2][2];
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) {res[i][j]+=(a[i][k]*b[k][j])%m; res[i][j]%=m;}
		return res;
	}
	static long gcd(long x,long y){
		if(Math.max(x, y)%Math.min(x, y)==0) return Math.min(x, y);
		else return gcd(Math.min(x, y),Math.max(x, y)%Math.min(x,y));
	}
	static long pow(long a,long x){
		if(x==1) return a;
		else if(x%2==0) return pow((a*a)%m,x/2);
		else return (pow((a*a)%m,x/2)*a)%m;
	}
	public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        while(sc.hasNext()){
        	a=sc.nextLong();
        	b=sc.nextLong();
        	m=sc.nextLong();
        	long[][] ar={{10,1},{0,1}};
        	long d=gcd(a,b);
        	long[][] t1=pow(a-1,ar);
        	long res=(t1[0][0]%m+t1[0][1]%m)%m;
        	ar[0][0]=pow(10,d)%m;
        	long[][] t2=pow(b/d-1,ar);
        	res*=(t2[0][0]%m+t2[0][1]%m)%m;
        	System.out.println(res%m);
        }
    }
}