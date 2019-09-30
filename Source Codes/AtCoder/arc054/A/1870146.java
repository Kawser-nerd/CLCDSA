import java.util.Scanner;

class Main{
	static Scanner s=new Scanner(System.in);
	static int gInt(){return Integer.parseInt(s.next());}
	public static void main(String[]$){
		long
		l=gInt(),
		x=gInt(),
		y=gInt(),
		s=gInt(),
		d=gInt();

		long sl=y+x,sr=y-x;
		long dl=d>s?d-s:d+l-s;
		long dr=l-dl;
		
		double tl=dl*1.0/sl;
		double tr=sr<=0?1145141919:dr*1.0/sr;
		System.out.println(Math.min(tl,tr));
	}
}