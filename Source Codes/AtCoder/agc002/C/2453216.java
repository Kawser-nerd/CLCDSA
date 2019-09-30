import java.util.*;

class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){
		return Integer.parseInt(s.next());
	}
	public static void main(String[]A){
		int n=gInt(),l=gInt();
		int[]a=new int[n];
		int start=-1;
		a[0]=gInt();
		for(int i=1;i<n;++i) {
			a[i]=gInt();
			if(start<0&&a[i]+a[i-1]>=l)
				start=i;
		}
		if(start<0) {
			System.out.println("Impossible");
			return;
		}
		System.out.println("Possible");
		for(int i=1;i<start;++i)
			System.out.println(i);
		for(int i=n-1;i>=start;--i)
			System.out.println(i);
	}
}