

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.*;

class Edge {
	int x,y;
	int cost;
	
	Edge next;
}
class Node {
	int status=0; 
	int w=0;
	
	int px=-1,py=-1;
	
	char c;
	Edge head;
	public Node(char c) {
		this.c = c;
	}
	public void createEdge(int x, int y) {
		createEdge(x,y,1);
	}
	public void createEdge(int x, int y, int cost) {
		Edge e = new Edge();
		e.x = x;
		e.y = y;
		e.next = head;
		this.head = e;
		e.cost  = cost;
	}
	
}

public class B {
	// TODO: input data variables
	Node maze[][];
	int R,C;
	public void read() {
		R = in.nextInt();
		C = in.nextInt();
		maze = new Node[R+2][C+2];
		for(int i=0;i<=C+1;i++) {
			maze[0][i] = 
				maze[R+1][i] = new Node('#');
		}
		for(int i=1;i<=R;i++) {
			maze[i][0] = maze[i][C+1]=new Node('#');
			char tmp[]= in.next().toCharArray();
			for(int j=1;j<=C;j++) {
				maze[i][j]=new Node(tmp[j-1]);
			}
		}
//		con.println("-------------");
//		for(int i=0;i<=R+1;i++) {
//			for(int j=0;j<=C+1;j++) {
//				con.print(maze[i][j].c);
//			}
//			con.println();
//		}
//		con.println("--------------");
//		con.println("Map Read");
		
	}
	int step[][] = new int[][] {
			new int[] {1,0},
			new int[] {-1,0},
			new int[] {0,1},
			new int[] {0,-1}
		};
	int most[] [] = new int[4][2];
	int create() {
		int startx=-1,starty=-1;
		for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) if (maze[i][j].c!='#') {
			if (maze[i][j].c=='O') {
				startx = i;starty=j;
			}
						
			for(int t=0;t<4;t++) {
				int x = i+step[t][0];
				int y = j+step[t][1];
				if (maze[x][y].c!='#') {
//					con.println("edge: "+i+","+j+"->"+x+","+y);
					maze[i][j].createEdge(x,y);
				}
			}
			for(int t=0;t<4;t++) {
				int x = i;
				int y = j;
				int nx = i+step[t][0];
				int ny = j+step[t][1];
				while(maze[nx][ny].c != '#') {
					x = nx;
					y = ny;
					nx = x+step[t][0];
					ny = y+step[t][1];
				}
				most[t][0]=x; most[t][1]=y;
			}
//			con.println("for "+i+","+j);
			for(int m=0;m<4;m++) {
				int cost = dist(i,j,most[m][0],most[m][1]);
				for(int n=0;n<4;n++) if (m!=n) {
//					con.println("EDGE: "+i+","+j+"->"+most[n][0]+","+most[n][1]+" : "+cost);
					maze[i][j].createEdge(most[n][0], most[n][1],cost+1);
				}
			}
		} 
		if (startx<0 || starty<0) terminate("no start point");
		
		maze[startx][starty].status = 1;
		while(true) {
			// find next
			int x=-1,y=-1;
			for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) {
				if (maze[i][j].c!='#' && maze[i][j].status==1) {
					if (x<0 || maze[i][j].w < maze[x][y].w) {
						x = i; y = j;
					}
				}
			}
			if (x<0) break;
			if (maze[x][y].c=='X') {
//				int gx = x, gy = y;
//				while(gx>=0) {
//					con.println("Step :"+gx+","+gy+":"+maze[gx][gy].w);
//					int ngx = maze[gx][gy].px;
//					int ngy = maze[gx][gy].py;
//					gx =ngx; gy = ngy;
//				}
				return maze[x][y].w;
			}
			maze[x][y].status = 2;
			
			Edge e = maze[x][y].head;
			while(e!=null) {
				int nx=e.x;
				int ny=e.y;
				int newStep = maze[x][y].w+e.cost;
				if (maze[nx][ny].status==0) {
					maze[nx][ny].status = 1;
					maze[nx][ny].w = newStep;
					maze[nx][ny].px = x;
					maze[nx][ny].py = y;
				} else if (maze[nx][ny].status==1 && newStep < maze[nx][ny].w) {
					maze[nx][ny].w = newStep;
					maze[nx][ny].px = x;
					maze[nx][ny].py = y;
				}
				e =e .next;
			}
		}
		// not reachable
		return -1;
	}
	// TODO: define answer variable, e.g. long count;
	
	private int dist(int i, int j, int k, int l) {
		// TODO Auto-generated method stub
		int dx = i-k;
		int dy = j-l;
		if (dx<0) dx = -dx;
		if (dy<0) dy = -dy;
		return dx+dy;
	}

	// TODO: define working variables
	public void work() {
		
	}
	public void kill() {
		int ___N; 
		___N = in.nextInt();
		in.nextLine();
		for(int tc=1;tc<=___N;tc++) {
			read();
			int ans = create(); //work();
			out.print("Case #"+tc+": ");
			out.print(ans>=0?""+ans:"THE CAKE IS A LIE");
			// TODO: print answer here
			out.println();
		}
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		B self = new B();
		self.init();
		self.kill();
		self.clean();
		self.con.println("done");
	}

	
	// Below is for i/o only -------------------------------
	Scanner in;
	PrintStream out;
	PrintStream con;
	// PrintWriter out;
	
	public void init() throws IOException {
		con = System.err;
		
		BufferedReader console = new BufferedReader(
					new InputStreamReader(System.in));
		System.err.print("Read from (empty for stdin/stdout):");
		String in = console.readLine();
		if (in.length() == 0) {
			this.in =  new Scanner(System.in);
			this.out = System.out;
		} else {
			int pos = in.lastIndexOf(".");
			if (pos<0) {
				pos = in.length();
				in += ".in";
			}
			this.in =  new Scanner(new FileReader(in));
			in = in.substring(0,pos);
			
			String out = in + ".out";
			int k = 0;
			while (new java.io.File(out).exists()) {
				out = in + ".out"+(++k);
			}
			if (k>0) {
				System.err.println("Warn: Output file exists. Rename to "+out);
			}
			this.out = new PrintStream(out);
		}
	}
	public void clean() {
		in.close();
		out.flush();
		out.close();		
	}
	public void terminate(String war) {
		con.println(war);
		throw new java.lang.RuntimeException("Error:"+war);
		// System.exit(1);
	}
	
	// common procedures
	static public int gcd(int a, int b) {
		while (b>0) {
			int tmp = a % b;
			a = b; b = tmp;
		}
		return a;
	}
}
