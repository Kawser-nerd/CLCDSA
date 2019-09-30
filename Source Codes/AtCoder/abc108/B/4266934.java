import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] x1y1x2y2 = br.readLine().split(" ");
		int x1 = Integer.parseInt(x1y1x2y2[0]);
		int y1 = Integer.parseInt(x1y1x2y2[1]);
		int x2 = Integer.parseInt(x1y1x2y2[2]);
		int y2 = Integer.parseInt(x1y1x2y2[3]);
		Point p1 = new Point(x1, y1);
		Point p2 = new Point(x2, y2);
		Square ruinedSquare = new Square(p1, p2);
		Square recoveredSquare = ruinedSquare.recover();
		System.out.println(recoveredSquare);
	}

}
class Square{
	private Point p1, p2, p3, p4;
	public Square(Point p1, Point p2) {
		this.p1 = p1;
		this.p2 = p2;
	}
	public Square() {} // default constructor
	
	public Square(Point p1, Point p2, Point p3, Point p4) {
		this.p1 = p1;	this.p2 = p2;	this.p3 = p3;	this.p4 = p4;
	}
	private Point nextPointOf(Point a, Point b) {
		int x = b.x - a.x;	int y = b.y - a.y;
		return new Point(b.x - y, b.y + x);
	}
	public Square recover() {
		this.p3 = this.nextPointOf(this.p1, this.p2);
		this.p4 = this.nextPointOf(this.p2, this.p3);
		Square recoveredSquare = new Square(this.p1, this.p2, this.p3, this.p4);
		return recoveredSquare;
	}
	@Override public String toString() {
		String s = String.format("%d %d %d %d\n", this.p3.x, this.p3.y, this.p4.x, this.p4.y);
		return s;
	}
}