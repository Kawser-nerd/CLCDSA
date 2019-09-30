import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	int R,C,N;
	ArrayList<Point> edge;

	private void solve() {

		Scanner io = new Scanner(System.in);
		R = io.nextInt();
		C = io.nextInt();
		N = io.nextInt();
		
		edge = new ArrayList<Point>();

		for(int i=0;i<N;i++){
			int x1 = io.nextInt();
			int y1 = io.nextInt();
			int x2 = io.nextInt();
			int y2 = io.nextInt();
			
			int p1 = trans(x1,y1);
			int p2 = trans(x2,y2);
			if(p1==-1||p2 ==-1) continue;
			
			edge.add(new Point(p1,i));
			edge.add(new Point(p2,i));
			
		}
		
		Collections.sort(edge);
		
		LinkedList<Point> stack = new LinkedList<Point>();
		for(int i=0;i<edge.size();i++){
			if(stack.isEmpty()){
				stack.push(edge.get(i));
			}else{
				if(stack.peek().id==edge.get(i).id){
					stack.pop();
				}else{
					stack.push(edge.get(i));
				}
			}
		}

		System.out.println((stack.isEmpty())?"YES":"NO");
	}
	
	private int trans(int x,int y){
		if(y==0){
			return x;
		}else if(x==R){
			return R+y;
		}else if(y==C){
			return 2*R+C-x;
		}else if(x==0){
			return 2*R+2*C-y;
		}else{
			return -1;
		}
	}
	
	public static void main(String[] args) {
		new Main().solve();
	}
}

class Point implements Comparable<Point>{
	int pos;
	int id;
	// equals method must be changed !! 
	
	public Point(int x,int y){
		this.pos = x;
		this.id = y;
	}

	@Override
	public boolean equals(Object o){
		return pos == ((Point)o).pos &&
			   id == ((Point)o).id;
	}
	@Override
	public int compareTo(Point o) {
		return Integer.compare(this.pos,o.pos);
	}
	@Override
	public int hashCode(){
		return Integer.hashCode(pos*id);
	}
}