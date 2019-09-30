import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){
		return IntStream.range(0,v);
	}
	static IntStream REPS(int l,int r){
		return IntStream.rangeClosed(l,r);
	}
	static IntStream INS(int n){
		return REPS(n).map(i->getInt());
	}
	static int getInt(){
		return Integer.parseInt(s.next());
	}
	public static void main(String[]$){
		int n=getInt(),k=getInt();
		String v=s.next();
		StringBuilder r=new StringBuilder();
		int[]_v=new int[26],_r;
		v.chars().forEach(i->++_v[i-'a']);
		_r=Arrays.copyOf(_v,26);

		for(int i=0;i<n;++i){
			long d=n-1-i
					+REPS(r.length())
					.filter(o->v.charAt(o)!=r.charAt(o))
					.count();
			--_v[v.charAt(i)-'a'];
			for(int c=0;c<26;c++) if(_r[c]>0){
				--_r[c];
				if(d+(c!=v.charAt(i)-'a'?1:0)
						-REPS(0,25).map(o->Math.min(_v[o],_r[o])).sum()
						<=k){
					r.append((char)('a'+c));
					break;
				}
				++_r[c];
			}
		}
		System.out.println(r);
	}
}