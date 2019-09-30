import java.util.*;
public class Main{
  public static void main(String[]args){
  Scanner sc=new Scanner(System.in);
  int a=sc.nextInt()-1;
  int b=sc.nextInt()-1;
    System.out.println(combination(a+b,Math.min(b,a),1000000007));
  }
public static long factorial(int a,int p) {
		long ans=1;
		for(int i=1;i<=a;i++) {
			ans=(p==0)?ans*i:(ans*i)%p;
		}
		return ans;
	}
	public static long permutation(int a,int b,int p) {
		long ans=1;
		if(a>b) {
			int c=a;
			a=b;
			b=c;
		}
		for(int i=b;i>b-a;i--) {
			ans=(p==0)?ans*i:(ans*i)%p;
		}
		return ans;
	}
	public static long combination(int a,int b,int p) {
		long c=permutation(a,b,p);
		long c2=factorial(b,p);
		c=(p==0)?c/c2:(p==1)?0:c*pow((int)c2,p-2,p);
		return (p==0)?(int)c:(int)(c%p);
	}
public static int pow(int a,int b,int p) {
		if(b==0) {
			return 1;
		}
		else if(b%2==0) {
			long c=(p==0)?(long)a*a:((long)a*a)%p;
			return pow((int)c,b/2,p);
		}
		else {
			long c=(p==0)?(long)a*pow(a,b-1,p):((long)a*pow(a,b-1,p))%p;
			return (int)c;
		}
	}
}