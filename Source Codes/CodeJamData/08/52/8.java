package round3;

import java.util.Scanner;

public class Portal {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			int r = scanner.nextInt();
			int c = scanner.nextInt();
			char[][] map = new char[r][];
			for (int j = 0; j < r; j++) {
				String line = scanner.next();
				map[j] = line.toCharArray();
			}
			Point[][] distUnknown = new Point[r][c];
			Point end = null;
			for (int j=0; j<r;j++) {
				for (int k=0; k<c; k++) {
					if (map[j][k] == '#') continue;
					Point point = new Point(j,k);
					for (int m=0; m < r+c; m++) {
						if (m>j ||
							m>k ||
							m+k>=c ||
							m+j>=r ||
							map[j-m][k] == '#' ||
							map[j+m][k] == '#' ||
							map[j][k-m] == '#' ||
							map[j][k+m] == '#') {
							point.setWallDist(m);
							break;
						}
					}
					distUnknown[j][k] = point;
					if (map[j][k] == 'O') {
						point.setDist(0);
					}
					else {
						if (map[j][k] == 'X') {
							end = point;
						}
					}
				}
			}
			while (true) {
				int dist = Integer.MAX_VALUE;
				Point p = null;
				for (int j=0; j<r;j++) {
					for (int k=0; k<c; k++) {
						Point temp = distUnknown[j][k];
						if (temp != null && temp.dist < dist) {
							dist = temp.dist;
							p = temp;
						}
					}
				}
				if (p == null) {
					break;
				}
				if (p.x > 0 && distUnknown[p.x-1][p.y] != null) {
					if (distUnknown[p.x-1][p.y].dist > p.dist) {
						distUnknown[p.x-1][p.y].dist = p.dist+1;
					}
				}
				if (p.y > 0 && distUnknown[p.x][p.y-1] != null) {
					if (distUnknown[p.x][p.y-1].dist > p.dist) {
						distUnknown[p.x][p.y-1].dist = p.dist+1;
					}
				}
				if (p.x < r-1 && distUnknown[p.x+1][p.y] != null) {
					if (distUnknown[p.x+1][p.y].dist > p.dist) {
						distUnknown[p.x+1][p.y].dist = p.dist+1;
					}
				}
				if (p.y < c-1 && distUnknown[p.x][p.y+1] != null) {
					if (distUnknown[p.x][p.y+1].dist > p.dist) {
						distUnknown[p.x][p.y+1].dist = p.dist+1;
					}
				}
				int j = 0;
				while (true) {
					if (p.x-j < 0 || map[p.x-j][p.y]=='#') break;
					j++;
				}
				j--;
				if (distUnknown[p.x-j][p.y] != null) {
					if (distUnknown[p.x-j][p.y].dist > p.dist + p.wallDist) {
						distUnknown[p.x-j][p.y].dist = p.dist + p.wallDist;
					}
				}
				j = 0;
				while (true) {
					if (p.y-j < 0 || map[p.x][p.y-j]=='#') break;
					j++;
				}
				j--;
				if (distUnknown[p.x][p.y-j] != null) {
					if (distUnknown[p.x][p.y-j].dist > p.dist + p.wallDist) {
						distUnknown[p.x][p.y-j].dist = p.dist + p.wallDist;
					}
				}
				j = 0;
				while (true) {
					if (p.x+j >= r || map[p.x+j][p.y]=='#') break;
					j++;
				}
				j--;
				if (distUnknown[p.x+j][p.y] != null) {
					if (distUnknown[p.x+j][p.y].dist > p.dist + p.wallDist) {
						distUnknown[p.x+j][p.y].dist = p.dist + p.wallDist;
					}
				}
				j = 0;
				while (true) {
					if (p.y+j >= c || map[p.x][p.y+j]=='#') break;
					j++;
				}
				j--;
				if (distUnknown[p.x][p.y+j] != null) {
					if (distUnknown[p.x][p.y+j].dist > p.dist + p.wallDist) {
						distUnknown[p.x][p.y+j].dist = p.dist + p.wallDist;
					}
				}
				distUnknown[p.x][p.y]=null;
			}
			if (end.dist == Integer.MAX_VALUE) {
				System.out.printf("Case #%d: THE CAKE IS A LIE\n",i);
			}
			else {
				System.out.printf("Case #%d: %d\n",i,end.dist);
			}
		}
	}
	
	public static class Point {
		public final int x;
		public final int y;
		private int wallDist;
		private int dist = Integer.MAX_VALUE;		
		
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int getWallDist() {
			return wallDist;
		}

		public void setWallDist(int wallDist) {
			this.wallDist = wallDist;
		}

		public int getDist() {
			return dist;
		}

		public void setDist(int dist) {
			this.dist = dist;
		}

		public boolean equals(Object o) {
			if (o.getClass().equals(o)) {
				Point p = (Point) o;
				return p.x==this.x && p.y == this.y;
			}
			return false; 
		}

		public int hashCode() {
			return x + y*16;
		}
		
	}
}
