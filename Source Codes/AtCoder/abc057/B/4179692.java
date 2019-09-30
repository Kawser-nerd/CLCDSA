//

import java.util.Scanner;

class Main {
	static Scanner sc = new Scanner(System.in);
	static int mod = 1000000007;
	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		Point[] student = new Point[n];
		Point[] checkPoint = new Point[m];
		for (int i=0; i<n; i++) student[i] = new Point(sc.nextInt(), sc.nextInt());
		for (int i=0; i<m; i++) checkPoint[i] = new Point(sc.nextInt(), sc.nextInt());
		
		for (int i=0; i<n; i++) {
			int minNum = -1;
			int minValue = Integer.MAX_VALUE;
			for (int j=0; j<m; j++) {
				int d = calcManhatDistance(student[i].getX(), student[i].getY(), checkPoint[j].getX(), checkPoint[j].getY());
				if (d < minValue) {
					minValue = d;
					minNum = j;
				}
			}
			System.out.println(minNum+1);
		}
		
	}

	static int calcManhatDistance (int x1, int y1, int x2, int y2) {
		int d = Math.abs(x1-x2)+Math.abs(y1-y2);
		return d;
	}
	static double calcEuclidDistance (double x1, double y1, double x2, double y2) {
		double d = Math.sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		return d;
	}

}

class Point{
	private int x;
	private int y;

	Point(int a, int b) {x=a; y=b;}

	int getX() {return x;}
	int getY() {return y;}
	void setX(int n) {x = n;}
	void setY(int n) {y = n;}
}