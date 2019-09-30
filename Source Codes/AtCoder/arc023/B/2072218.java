import java.util.*;
class Main{
	public static void main(String[]$){
		Scanner s=new Scanner(System.in);
		int h=s.nextInt(),w=s.nextInt(),d=s.nextInt(),r=0;
		for(int i=0;i<h;++i)
			for(int j=0;j<w;++j)
				r=Math.max(r,s.nextInt()*((i+j<=d&&(d-i-j)%2==0)?1:0));
		System.out.println(r);
	}
}