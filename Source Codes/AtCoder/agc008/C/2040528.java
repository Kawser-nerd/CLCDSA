import java.util.*;
class Main{
	static Scanner s=new Scanner(System.in);
	public static void main(String[]$){
		long i=g(),o=g(),t=g(),j=g(),l=g(),r=l/2*2+j/2*2+i/2*2;
		if(l>0&&j>0&&i>0)
			r=Math.max(r,3+(l-1)/2*2+(j-1)/2*2+(i-1)/2*2);
		System.out.println(r+o);
	}
	static long g(){
		return s.nextLong();
	}
}