import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n){return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}


	static class E{
		String t;
		int i;
		public E(String t,int i){
			this.t=t;
			this.i=i;
		}
		public int getI(){
			return this.i;
		}
		public int getL(){
			return this.t.length();
		}
		public String getT(){
			return this.t;
		}
	}

	public static void main(String[]$){
		int[]order=new int[10];
		REPS(10).forEach(i->order[getInt()]=i);

		ArrayList<E>m=new ArrayList<>();
		for(int i=getInt();i>0;--i) {
			String in=s.next();
			char[]c=in.toCharArray();
			for(int j=0;j<c.length;++j) {
				c[j]=(char)(order[c[j]-'0']+'0');
			}
			m.add(new E(in,Integer.parseInt(String.valueOf(c))));
		}

		m.stream()
		.sorted(Comparator.comparingInt(E::getL).thenComparingInt(E::getI))
		.map(E::getT)
		.forEach(System.out::println);
 	}
}