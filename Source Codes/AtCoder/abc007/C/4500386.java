import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	private static final String NG = "#";

	private static final int NO_ENTRY = -2;

	private static final int ENTRY = -1;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int line = sc.nextInt();
		int column = sc.nextInt();
		int startX = sc.nextInt() - 1;
		int startY = sc.nextInt() - 1;
		int endX = sc.nextInt() - 1;
		int endY = sc.nextInt() - 1;
		int[][] arr = new int[line][column];
		String tempLine;
		String[] temp;
		for (int i = 0; i < line; i++) {

			tempLine = sc.next();
			temp = tempLine.split("");

			for (int j = 0; j < column; j++) {

				if (temp[j].equals(NG)) {
					arr[i][j] = NO_ENTRY;
				} else {
					arr[i][j] = ENTRY;
				}
			}
		}
		sc.close();

		int[][] result = solve(arr, startX, startY);

		System.out.println(result[endX][endY]);
	}

	private static int[][] solve(int[][] arr, int startX, int startY) {

		arr[startX][startY] = 0;

		Point point = new Point(startX, startY);
		List<Point> pList = new ArrayList<>();
		pList.add(point);

		while (pList.size() > 0) {

			Point p = pList.get(0);
			pList.remove(0);

			int tempX = p.getX();
			int tempY = p.getY();

			if (arr[tempX][tempY + 1] == ENTRY) {
				// ????
				pList.add(new Point(tempX, tempY + 1));
				arr[tempX][tempY + 1] = arr[tempX][tempY] + 1;
			}

			if (arr[tempX][tempY - 1] == ENTRY) {
				// ????
				pList.add(new Point(tempX, tempY - 1));
				arr[tempX][tempY - 1] = arr[tempX][tempY] + 1;
			}

			if (arr[tempX - 1][tempY] == ENTRY) {
				// ????
				pList.add(new Point(tempX - 1, tempY));
				arr[tempX - 1][tempY] = arr[tempX][tempY] + 1;
			}

			if (arr[tempX + 1][tempY] == ENTRY) {
				// ????
				pList.add(new Point(tempX + 1, tempY));
				arr[tempX + 1][tempY] = arr[tempX][tempY] + 1;
			}

		}
		return arr;
	}
}

class Point {

	private int x;

	private int y;

	public Point(int x, int y) {
		super();
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return x;
	}

	public int getY() {
		return y;
	}
}