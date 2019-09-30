
public class Point {

	public double x, y;
	
	public Point(double x, double y)
	{
		this.x = x;
		this.y = y;
	}
	
	public Point() {
		x=0; y=0;
	}

	@Override
	public boolean equals(Object arg0) {
		Point pt = (Point)arg0;
		return CG.dblcmp(pt.x, x) == 0 && CG.dblcmp(pt.y, y) == 0;
	}

	public Point minus(Point p)
	{
		return new Point(x-p.x, y-p.y);
	}
	public Point add(Point p)
	{
		return new Point(x+p.x, y+p.y);
	}
	public Point mul(double n)
	{
		return new Point(n*x, n*y);
	}
	public double abs()
	{
		return Math.sqrt(x*x + y*y);
	}
	public void copy(Point p)
	{
		this.x = p.x;
		this.y = p.y;
	}

}
