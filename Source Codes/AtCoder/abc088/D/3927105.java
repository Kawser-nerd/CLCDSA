import java.util.*;
import java.awt.Point;
class Main {
    static Queue<Point> q;
    static int[][] count;
    static char[][] maze;
    static int H,W;
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	H = sc.nextInt();
	W = sc.nextInt();
	maze = new char[H][W];
	count = new int[H][W];
	int white = 0;
	for(int i = 0; i<H; i++) {
	    for(int j = 0; j<W; j++) {
		count[i][j] = 100000;
	    }
	}
	for(int i = 0; i<H; i++) {
	    String line = sc.next();
	    for(int j = 0; j<W; j++) {
		maze[i][j] = line.charAt(j);
		if(maze[i][j] == '.') white++;
	    }
	}

	count[0][0] = 1;
	q = new ArrayDeque<Point>();
	q.add(new Point(0,0));
	while(q.peek() != null) {
	    Point p = q.poll();
	    if(p.getX() == H-1 && p.getY() == W-1) break;
	    addPQ(p);
	}
	int result = count[H-1][W-1];
	if(result < 100000) {
	    System.out.println(white - count[H-1][W-1]);
	}else {
	    System.out.println(-1);
	}
    }
    public static void addPQ(Point p) {
	int x = (int)(p.getX());
	int y = (int)(p.getY());
	//System.out.println("x : y" + x +" , "+ y);
	if(maze[x][y] =='#') return;
	maze[x][y] = '#';
	if(x+1<H && maze[x+1][y] == '.') {
	    q.add(new Point(x+1,y));
	    count[x+1][y] = count[x][y] + 1;
	}
	if(x-1>=0 && maze[x-1][y] == '.') {
	    q.add(new Point(x-1,y));
	    count[x-1][y] = count[x][y]+ 1;
	}
	if(y+1<W && maze[x][y+1] == '.') {
	    q.add(new Point(x, y+1));
	    count[x][y+1] = count[x][y]+ 1;
	}
	if(y-1>=0 && maze[x][y-1] == '.') {
            q.add(new Point(x,y-1));
	    count[x][y-1] = count[x][y]+ 1;
	}
    }
}