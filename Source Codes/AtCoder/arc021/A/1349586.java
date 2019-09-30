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
		int[][]in=REPS(4).mapToObj(i->INTS(4).toArray()).toArray(int[][]::new);
		
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				if(i>0 && in[i-1][j]==in[i][j]) {
					hoge();
					return;
				}
				if(i<3 && in[i+1][j]==in[i][j]) {
					hoge();
					return;
				}
				if(j>0 && in[i][j-1]==in[i][j]) {
					hoge();
					return;
				}
				if(j<3 && in[i][j+1]==in[i][j]) {
					hoge();
					return;
				}
			}
		}
		System.out.println("GAMEOVER");
	}
	private static void hoge(){
		System.out.println("CONTINUE");
	}
}