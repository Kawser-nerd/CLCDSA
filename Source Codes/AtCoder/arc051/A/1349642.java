import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main{
	static final Scanner s=new Scanner(System.in);
	static int getInt(){
		return Integer.parseInt(s.next());
	}
	public static void main(String[] __){
		int x=getInt(),y=getInt(),r=getInt();
		Ellipse2D.Double red=new Ellipse2D.Double(x-r,y-r,r*2,r*2);
		x=getInt();
		y=getInt();
		int xx=getInt(),yy=getInt();
		Rectangle2D.Double blue=new Rectangle2D.Double(x,y,xx-x,yy-y);
System.out.println(blue.contains(red.getBounds2D())?"NO":"YES");
		System.out.println(red.contains(blue)?"NO":"YES");
	}
}