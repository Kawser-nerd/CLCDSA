import java.util.Scanner;
import java.util.stream.IntStream;
 
public class Main{
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n) {return REPS(n).map(i->getInt());}
	static Scanner s=new Scanner(System.in);
	static int getInt(){return Integer.parseInt(s.next());}
 
	public static void main(String[]$){
		int
		a=getInt(),
		b=getInt(),
		c=getInt(),
		d=getInt(),
		e=getInt(),
		f=getInt();
 
		int rw=100*a,rs=0;
		double max=0;
 
		for(int i=0;true;++i) {
			int va=100*a*i;
			if(va>f)
				break;
			for(int j=0;true;++j) {
				int vb=100*b*j;
				if(va+vb>f)
					break;
				for(int k=0;true;++k) {
					int vc=c*k;
					if(va+vb+vc>f)
						break;
					for(int l=0;true;++l) {
						int vd=d*l;
						if(va+vb+vc+vd>f)
							break;
						if(max<calc(va+vb,vc+vd,e)) {
							max=calc(va+vb,vc+vd,e);
							rw=va+vb;
							rs=vc+vd;
						}
					}
				}
			}
		}
		System.out.println(rw+rs+" "+rs);
	}
	private static double calc(int w,int s,int e){
		double r=w==0?0:100.0*s/(w+s);
		return w/100*e<s?0:r;
	}
}