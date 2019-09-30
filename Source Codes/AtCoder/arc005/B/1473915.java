import java.awt.Point;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static IntStream REPS(int v){return IntStream.range(0,v);}
	static IntStream REPS(int l,int r){return IntStream.rangeClosed(l,r);}
	static IntStream INS(int n){return REPS(n).map(i->getInt());}
	static int getInt(){return Integer.parseInt(s.next());}

	public static void main(String[]$){
		Point p=new Point(getInt()-1,getInt()-1);
		String w=s.next();
		char[][]f=REPS(9).mapToObj(i->s.next().toCharArray()).toArray(char[][]::new);

		w=turn(w,p);

		for(int l=0;l<4;++l) {
			System.out.print(f[p.y][p.x]);
			if(l==3) {
				System.out.println();
				return;
			}

			switch(w){
			case "R":
				++p.x;
				break;
			case "L":
				--p.x;
				break;
			case "U":
				--p.y;
				break;
			case "D":
				++p.y;
				break;
			case "RU":
				++p.x;
				--p.y;
				break;
			case "RD":
				++p.x;
				++p.y;
				break;
			case "LU":
				--p.x;
				--p.y;
				break;
			case "LD":
				--p.x;
				++p.y;
				break;
			}
			w=turn(w,p);
		}
 	}
	private static String turn(String w,Point p){
		switch(w){
		case "R":
			if(p.x==8)
				return "L";
			break;
		case "L":
			if(p.x==0)
				return "R";
			break;
		case "U":
			if(p.y==0)
				return "D";
			break;
		case "D":
			if(p.y==8)
				return "U";
			break;
		case "RU":
			if(p.x==8&&p.y==0)
				return "LD";
			if(p.x==8)
				return "LU";
			if(p.y==0)
				return "RD";
			break;
		case "RD":
			if(p.x==8&&p.y==8)
				return "LU";
			if(p.x==8)
				return "LD";
			if(p.y==8)
				return "RU";
			break;
		case "LU":
			if(p.x==0&&p.y==0)
				return "RD";
			if(p.x==0)
				return "RU";
			if(p.y==0)
				return "LD";
			break;
		case "LD":
			if(p.x==0&&p.y==8)
				return "RU";
			if(p.x==0)
				return "RD";
			if(p.y==8)
				return "LU";
			break;
		}
		return w;
	}
}