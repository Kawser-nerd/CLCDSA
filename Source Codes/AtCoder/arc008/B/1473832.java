import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n){return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}

	public static void main(String[]$){
		int[]name=new int[26],kit=new int[26];

		s.next();
		s.next();

		s.next().chars().forEach(i->++name[i-'A']);
		s.next().chars().forEach(i->++ kit[i-'A']);

		if(REPS(26).anyMatch(i->name[i]>0&&kit[i]==0)) {
			System.out.println(-1);
			return;
		}

		System.out.println(REPS(26).map(i->name[i]==0?0:(name[i]+kit[i]-1)/kit[i]).max().getAsInt());
	}
}