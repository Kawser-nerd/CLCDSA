import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n) {return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}

	static class Pair<T,U>{
		T l;
		U r;
		Pair(T l,U r){
			this.l=l;
			this.r=r;
		}
		T getL(){
			return l;
		}
		U getR(){
			return r;
		}
	}

	public static void main(String[]$){
		int[]p=new int[10];
		for(int i=0;i<10;++i)
			p[getInt()]=i;

		ArrayList<Pair<String,Integer>> l=new ArrayList<>();

		REPS(getInt()).mapToObj(i->s.next()).forEach(o->{
			char[]v=o.toCharArray();
			for(int x=0;x<v.length;++x) {
				v[x]=(char)(p[v[x]-'0']+'0');
			}
			l.add(new Pair<>(
					o,
					Integer.parseInt(String.valueOf(v))
					));
		});
		//l.stream().map(Pair::getR).forEach(System.out::println);

		l.stream().sorted(
				Comparator.<Pair<String,Integer>,Integer>comparing(Pair::getR))
		.map(Pair::getL)
		.forEach(System.out::println);
	}
}