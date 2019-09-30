import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n) {return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}

	public static void main(String[]$){
		int n=getInt(),m=getInt();
		char[]c=new char[26],k=new char[26];
		s.next().chars().forEach(i->++c[i-'A']);
		s.next().chars().forEach(i->++k[i-'A']);
		if(REPS(26).anyMatch(i->c[i]>0&&k[i]==0)) {
			System.out.println(-1);
			return;
		}
		System.out.println(
				REPS(26).filter(i->c[i]!=0)
				.map(i->(c[i]+k[i]-1)/k[i])
				.max().getAsInt()
				);
	}
}