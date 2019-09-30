import java.util.*;
public class Main{
	public static void main(String... argv){
		//??
		Scanner in = new Scanner(System.in);
		int h = in.nextInt(); int w = in.nextInt();
		char[][] map = new char[h][w];
		for(int i=0;i<h;i++){
			String str = in.next();
			map[i] = str.toCharArray();
		}
		in.close();
		//?????
		if(wfs(map,h,w))
			System.out.println("YES");
		else
			System.out.println("NO");
	}
	//nokori:?????????????map:??, h:???????(?:+) w:??????(?:+)
	static boolean wfs(char[][] map, int h, int w){
		int[][] costs = new int[h][w];
		Deque<Node> que = new LinkedList<Node>();
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				costs[i][j] = 3;
				if(map[i][j]=='s'){
					costs[i][j] = 0;
					que.offer(new Node(i,j, 0));
				}
			}
		}
		//????
		int[] steph = {1, 0, 0, -1};
		int[] stepw = {0, 1, -1, 0};
		while(!que.isEmpty()){
			Node node = que.remove();
			int y = node.getH();
			int x = node.getW();
			int cost = node.getCost();
			for(int i=0;i<4;i++){
				int next_x = x + stepw[i];
				int next_y = y + steph[i];
				if(!ok(next_y, next_x, h, w)) continue;
				if(map[next_y][next_x]=='g') return true;
				if(costs[next_y][next_x]<=cost)	continue;
				if(map[next_y][next_x]=='#' && cost < 2){
					costs[next_y][next_x] = cost+1;
					que.offer(new Node(next_y, next_x, cost+1));
				}
				if(map[next_y][next_x]=='.'){
					costs[next_y][next_x] = cost;
					que.offer(new Node(next_y, next_x, cost));
				}
			}
		}
		return false;
	}
	//map?????????
	static boolean ok(int i,int j,int h,int w) {
		return i >= 0 && i < h && j >= 0 && j < w;
	}
}

class Node{
	int h;
	int w;
	int cost;
	public Node(int h, int w, int cost){
		this.h = h;
		this.w = w;
		this.cost = cost;
	}
	public int getH(){
		return h;
	}
	public int getW(){
		return w;
	}
	public int getCost(){
		return cost;
	}
}