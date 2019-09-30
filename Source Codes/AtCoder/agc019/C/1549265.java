import java.awt.*;
import java.util.*;
class Main{
	static Scanner s=new Scanner(System.in);
	static int getInt(){return Integer.parseInt(s.next());}
	public static void main(String[]$){
		Point st=new Point(getInt(),getInt()),go=new Point(getInt(),getInt());
		if(st.y>go.y) {
			Point buf=go;
			go=st;
			st=buf;
		}
		Comparator<Point>c=Comparator.comparingDouble(Point::getX);
		TreeSet<Point>p=new TreeSet<>(st.x<go.x?c:c.reversed());
		for(int i=getInt();i>0;--i) {
			int x=getInt(),y=getInt();
			if(st.y<=y&&y<=go.y)
				p.add(new Point(x,y));
		}
		int v=lis(p.subSet(st,true,go,true));
		System.out.println(
				(Math.abs(st.x-go.x)+Math.abs(st.y-go.y))*100L
				+v*-20
				+(v==Math.min(go.y-st.y,Math.abs(go.x-st.x))+1?
						(v+1)
						:v)
				*5*Math.PI
				);
	}
	private static int lis(NavigableSet<Point> p){
		if(p.isEmpty())return 0;
		ArrayList<Integer>l=new ArrayList<>();
		l.add(p.pollFirst().y);
		while(!p.isEmpty()){
			int y=p.pollFirst().y;
			if(l.get(l.size()-1)<y)
				l.add(y);
			else {
				int v=Collections.binarySearch(l,y);
				if(v<0)
					l.set(~v,y);
			}
		}
		return l.size();
	}
}