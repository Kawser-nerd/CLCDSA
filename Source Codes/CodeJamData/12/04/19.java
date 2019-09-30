package google.codejam2012.qualification;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.*;

final class BinaryMatrix {
	
	private int[] data;
	
	public BinaryMatrix(int height, int width) {
		data = new int[height];
	}
	
	public void set(int row, int col) {
		data[row] |= 1 << col;
	}
	
	public boolean isEmpty(int row, int col) {
		return (data[row] & (1 << col)) == 0;
	}
}

public strictfp class HallOfMirrors {
	
	static private double eps = 1e-8;

	static private int gcd(int a, int b) {
		while (a > 0 & b > 0) {
			if (b > 0) a %= b;
			if (a > 0) b %= a;
		}
		return a + b;
	}
	
	// - simple reflections checker
	static private boolean isSimpleReflectionVisible(BinaryMatrix hall, int row, int col, int dr, int dc, int dist) {
		dist -= 1;
		row += dr;
		col += dc;
		while(dist >= 0 & hall.isEmpty(row, col)) {
			row += dr;
			col += dc;
			dist -= 2;
		}
		return dist >= 0;
	}
	
	static private double euclideanDistance(double dx, double dy) {
		return sqrt(dx * dx + dy * dy);
	}
	
	static private boolean isReflectionVisible(BinaryMatrix hall, int row, int col, double distance, double ax, double ay) {
		int r = row;
		int c = col;
		double distPassed = 0.0;
		double x = c + 0.5;
		double y = r + 0.5;
		int dr = ay > 0 ? 1 : -1;
		int dc = ax > 0 ? 1 : -1;
		while (distPassed < distance + eps) {
			double nx = ax > 0 ? (int) (x + eps) + 1.0 : (int) (x - eps);
			double ny = ay > 0 ? (int) (y + eps) + 1.0 : (int) (y - eps);
			double scenario = abs((x - nx) / ax) - abs((y - ny) / ay);
			// - corner
			if (abs(scenario) < eps) {
				r += dr;
				c += dc;
				distPassed += euclideanDistance(x - nx, y - ny);
				x = nx;
				y = ny;
				if (!hall.isEmpty(r, c)) {
					if (!hall.isEmpty(r - dr, c) & !hall.isEmpty(r, c - dc)) {
						distPassed += distPassed;
						break;
					}
					// - x
					else if (!hall.isEmpty(r - dr, c)) {
						ax = -ax;
						dc = -dc;
						c += dc;
					}
					// - y
					else if (!hall.isEmpty(r, c - dc)) {
						ay = -ay;
						dr = -dr;
						r += dr;
					}
					else {
						distPassed += distance + eps;
						break;
					}
				}
			}
			// - x
			else if (scenario < 0) {
				c += dc;
				ny = y + abs((x - nx) * ay / ax) * dr;
				distPassed += euclideanDistance(x - nx, y - ny);
				x = nx;
				y = ny;
				// - reflect
				if (!hall.isEmpty(r, c)) {
					ax = -ax;
					dc = -dc;
					c += dc;
				}
			}
			// - y
			else {
				r += dr;
				nx = x + abs((y - ny) * ax / ay) * dc;
				distPassed += euclideanDistance(x - nx, y - ny);
				x = nx;
				y = ny;				
				if (!hall.isEmpty(r, c)) {
					ay = -ay;
					dr = -dr;
					r += dr;
				}
			}
			// - check termination condition
			if (r == row & c == col) {
				double cx = c + 0.5;
				double cy = r + 0.5;
				if (abs((x - cx) / ax - (y - cy) / ay) < eps) {
					distPassed += euclideanDistance(cx - x, cy - y);
					break;
				}
			}
		}
		return distPassed < distance + eps;
	}
	
	static private int getVisibleReflectionsCount(BinaryMatrix hall, int row, int col, int distance) {
		int result = 0;
		// - check simple (up / down / left / right) reflections
		// -- up
		if (isSimpleReflectionVisible(hall, row, col, -1, 0, distance)) result++;
		// -- down
		if (isSimpleReflectionVisible(hall, row, col, 1,  0, distance)) result++;
		// -- left
		if (isSimpleReflectionVisible(hall, row, col, 0,  -1, distance)) result++;
		// -- right
		if (isSimpleReflectionVisible(hall, row, col, 0,  1, distance)) result++;
		
		// - check other kinds of reflections using ray tracing method
		for (int ax = 1; ax <= 250; ax++)
			for (int ay = 1; ay <= 250; ay++) 
			if (gcd(ax, ay) == 1) {
				if (isReflectionVisible(hall, row, col, distance, ax, ay)) result++;
				if (isReflectionVisible(hall, row, col, distance, -ax, ay)) result++;
				if (isReflectionVisible(hall, row, col, distance, ax, -ay)) result++;
				if (isReflectionVisible(hall, row, col, distance, -ax, -ay)) result++;
			}
		
		return result;
	}
	
	static public void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 64 << 10);
			int testsNumber = Integer.parseInt(br.readLine().trim());
			for (int test = 1; test <= testsNumber; test++) {
				// - read test data
				StringTokenizer tokenizer = new StringTokenizer(br.readLine());
				int height = Integer.parseInt(tokenizer.nextToken());
				int width = Integer.parseInt(tokenizer.nextToken());
				int distance = Integer.parseInt(tokenizer.nextToken());
				BinaryMatrix hall = new BinaryMatrix(height, width);
				int initialRow = 0;
				int initialCol = 0;
				for (int i = 0; i < height; i++) {
					String s = br.readLine();
					for (int j = 0; j < width; j++) {
						if (s.charAt(j) == '#') {
							hall.set(i, j);
						}
						else if (s.charAt(j) == 'X'){
							initialRow = i;
							initialCol = j;
						}
					}
				}
				int result = getVisibleReflectionsCount(hall, initialRow, initialCol, distance);
				System.out.println("Case #" + test + ": " + result);
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}