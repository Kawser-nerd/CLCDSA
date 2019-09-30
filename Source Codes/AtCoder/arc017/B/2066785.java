import java.util.*;
class Main{
	public static void main(String[]$){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),k=s.nextInt(),b=0,c=0,r=0;
		for(int i=0;i<n;++i){
			if(b<(b=s.nextInt()))
				++c;
			else {
				r+=c>=k?c-k+1:0;
				c=1;
			}
		}
		System.out.println(c>=k?r+c-k+1:r);
	}
}