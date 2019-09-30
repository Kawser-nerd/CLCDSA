import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main{
	static Scanner s=new Scanner(System.in);
	static int getInt(){return Integer.parseInt(s.next());}
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n) {return REPS(n).map(i->getInt());}
	static class Pair<T,U>{
		T l;U r;
		Pair(T L,U R){l=L;r=R;}
		T getL(){return l;}
		U getR(){return r;}
	}

	public static void main(String[]$){
		int n=getInt(),h=getInt();
		s.nextLine();
		List<Integer>l=REPS(1,n).boxed().collect(Collectors.toList());
		for(int i=0;i<h;++i) {
			String in=s.nextLine().replaceAll("[|]","");
			/*
			System.out.print("#");
			System.out.print(in);
			System.out.println("#");
			/**/
			for(int j=0;j<in.length();++j) {
				if(in.charAt(j)=='-')
					Collections.swap(l,j,j+1);
			}
			//System.out.println(l);
		}
		String e=s.nextLine();
		/*
		System.out.print(e);
		System.out.println("#");
		*/
		for(int i=0;i<n;++i)
			if(e.charAt(i*2)=='o')
				System.out.println(l.get(i));
	}
}