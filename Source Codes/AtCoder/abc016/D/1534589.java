import java.util.Scanner;

class Point {
	long x;
	long y;

	public Point(int x, int y) {
		super();
		this.x = x;
		this.y = y;
	}

}

class Line {
	Point start;
	Point end;

	public Line(Point start, Point end) {
		super();
		this.start = start;
		this.end = end;
	}

}

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int ax = sc.nextInt();
		int ay = sc.nextInt();
		int bx = sc.nextInt();
		int by = sc.nextInt();

		Line chopLine = new Line(new Point(ax, ay), new Point(bx, by));

		int N = sc.nextInt();

		Point[] points = new Point[N];
		for(int i=0; i<N; i++) {

			int x = sc.nextInt();
			int y = sc.nextInt();

			points[i] = new Point(x, y);

		}
		sc.close();

		Line[] lines = new Line[N];
		for(int i=0; i<N; i++) {
			lines[i] = new Line(points[i], points[(i+1)%N]);
		}

		int crossCount = 0;
		for(Line line : lines) {

			// ??????AB(chopLine.start, chopLine,end)?
			// lineCD(line.start, line.end)??????

			long checkA =
					(line.start.x - line.end.x) * (chopLine.start.y - line.start.y) +
					(line.start.y - line.end.y) * (line.start.x - chopLine.start.x);

			long checkB =
					(line.start.x - line.end.x) * (chopLine.end.y - line.start.y) +
					(line.start.y - line.end.y) * (line.start.x - chopLine.end.x);

			long checkC =
					(chopLine.start.x - chopLine.end.x) * (line.start.y - chopLine.start.y) +
					(chopLine.start.y - chopLine.end.y) * (chopLine.start.x - line.start.x);

			long checkD =
					(chopLine.start.x - chopLine.end.x) * (line.end.y - chopLine.start.y) +
					(chopLine.start.y - chopLine.end.y) * (chopLine.start.x - line.end.x);

			if(checkA * checkB < 0 && checkC * checkD < 0) {
				crossCount++;
			}

		}

		System.out.println(crossCount/2 + 1);

	}

}