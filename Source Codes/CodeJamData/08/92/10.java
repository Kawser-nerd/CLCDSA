
import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;

public class B {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int caseNum = sc.nextInt();
		for(int caseID = 1; caseID <= caseNum; caseID++){
			new B().solveDataSet(caseID);
		}
	}
	int W;
	int H;
	int dx1, dy1;
	int dx2, dy2;
	int ox, oy;
	HashSet<Int2D> visited;
	void solveDataSet(int caseID){
		W = sc.nextInt();
		H = sc.nextInt();
		dx1 = sc.nextInt();
		dy1 = sc.nextInt();
		dx2 = sc.nextInt();
		dy2 = sc.nextInt();
		ox = sc.nextInt();
		oy = sc.nextInt();
		visited = new HashSet<Int2D>();
		Queue<Int2D> q = new ArrayDeque();
		q.offer(new Int2D(ox, oy));
		while(!q.isEmpty()){
			Int2D p = q.poll();
			if(visited.contains(p)) continue;
			visited.add(p);
			Int2D p1 = new Int2D(p.x + dx1, p.y + dy1);
			Int2D p2 = new Int2D(p.x + dx2, p.y + dy2);
			if(isValid(p1)) q.offer(p1);
			if(isValid(p2)) q.offer(p2);
		}
		System.err.printf("Case #%d: %d%n", caseID, visited.size());
		System.out.printf("Case #%d: %d%n", caseID, visited.size());
	}
	boolean isValid(Int2D p){
		return 0 <= p.x && p.x < W && 0 <= p.y && p.y < H;
	}
}

class Int2D{
	int x, y;

	public Int2D(int x, int y) {
		super();
		this.x = x;
		this.y = y;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + x;
		result = prime * result + y;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		final Int2D other = (Int2D) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}
	
}
