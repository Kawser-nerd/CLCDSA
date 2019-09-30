import java.util.*;

class Main{
	static long[]l=new long[51];
	static long[]b=new long[51];
	
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		l[0]=1;
		b[0]=1;
		for(int i=1;i<l.length;++i) {
			l[i]=l[i-1]*2+3;
			b[i]=b[i-1]*2+1;
		}
		System.out.println(f(s.nextInt(),s.nextLong()));
	}

	static long f(int i,long a){
		if(a==l[i])
			return b[i];
		if(a>l[i-1]+2)
			return b[i-1]+1+f(i-1,a-l[i-1]-2);
		if(a==l[i-1]+2)
			return b[i-1]+1;
		if(a>1)
			return f(i-1,a-1);
		return 0;
	}
}