import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static int getInt(){
		return Integer.parseInt(s.next());
	}
	static IntStream REPS(int r){
		return IntStream.range(0,r);
	}
	static IntStream REPS(int l,int r){
		return IntStream.rangeClosed(l,r);
	}
	static IntStream INTS(int l){
		return REPS(l).map(i->getInt());
	}
	public static void main(String[] __){
		System.out.println(
				getDayFromEpic(2014,5,17)
				-getDayFromEpic(getInt(),getInt(),getInt())
				);
	}
	
	public static long getDayFromEpic(int y,int m,int d) {//(1,1,1)->0
		if(m<=2) {
			y--;
			m+=12;
		}
		return 365*y
				+ y/4
				- y/100
				+ y/400
				+ (306*(m+1))/10
				+ d - 429;
	}
	public static boolean isLeap(int y) {
		return y%4==0&&(y%100!=0||y%400==0);
	}
}