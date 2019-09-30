import java.util.*;

public class Main{
	private static Scanner sc=new Scanner(System.in);
	
	public static void main(String[] args){
		String[] date=sc.next().split("/");
		int y=Integer.parseInt(date[0]);
		int m=Integer.parseInt(date[1]);
		int d=Integer.parseInt(date[2]);
		Calendar c=Calendar.getInstance();
		c.set(y,m-1,d);
		while(!f(c))
			c.add(Calendar.DAY_OF_MONTH,1);
		y=c.get(Calendar.YEAR);
		m=c.get(Calendar.MONTH)+1;
		d=c.get(Calendar.DAY_OF_MONTH);
		System.out.printf("%4d/%02d/%02d\n",y,m,d);
	}
	
	public static boolean f(Calendar c){
		int y=c.get(Calendar.YEAR);
		int m=c.get(Calendar.MONTH)+1;
		int d=c.get(Calendar.DAY_OF_MONTH);
		return y%(m*d)==0;
	}
	
	private static int readInt(){
		return Integer.parseInt(sc.next());
	}
}