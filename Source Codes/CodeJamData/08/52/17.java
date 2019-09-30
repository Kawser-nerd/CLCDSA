package round3;

import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		for(int CASE = 1, N = sc.nextInt(); CASE <= N; CASE++) {
			
			System.out.printf("Case #%d: ", CASE);
			int r = sc.nextInt(), c = sc.nextInt();
			int[][] map = new int[r + 2][c + 2];
			int startX = -1, startY = -1;
			int goalX = -1, goalY = -1;
			for(int i = 1; i <= r; i++) {
				String str = sc.next();
				for(int j = 1; j <= c; j++) {
					char C = str.charAt(j - 1);
					if(C == 'O') {
						startX = j; startY = i;
						map[i][j] = 1;
					} else if(C == 'X') {
						goalX = j; goalY = i;
						map[i][j] = 1;
					} else if(C == '.') {
						map[i][j] = 1;
					}
				}
			}
			
			int[][][][] gun = new int[r + 2][c + 2][4][];
			for(int i = 1; i <= r; i++) {
				for(int j = 1; j <= c; j++) {
					if(map[i][j] == 1) {
						for(int k = 0; k < 4; k++) {
							int nx = j, ny = i;
							while(true) {
//								try{	
								if(map[ny + move[k][1]][nx + move[k][0]] == 0) {
									gun[i][j][k] = new int[]{nx, ny};
//									System.out.print("$"+i+" "+j+" "+
//											gun[i][j][k][0]+" "+gun[i][j][k][1]);
//									System.out.println(" "+move[k][0]+" "+move[k][1]);
									break;
								} else {
									nx += move[k][0]; ny += move[k][1];
//									System.out.println("%"+nx+" "+ny);
								}
//								}catch(Exception e) {
//									System.out.println(i+" "+j+" "+k+" "+nx+" "+ny);
//									System.exit(0);
//								}
							}
						}
					}
				}
			}
			
			Queue<Node> queue = new LinkedList<Node>();
			int[][][][] costs = new int[r + 2][c + 2][r + 2][c + 2];
			for(int[][][] tmp : costs) for(int[][] tmp2 : tmp)
				for(int[] tmp3 : tmp2) Arrays.fill(tmp3, -1);
			for(int i = 0; i < 4; i++) {
				queue.add(new Node(startX, startY, 0, 
						gun[startY][startX][i][0],
						gun[startY][startX][i][1]));
//				System.out.println("#"+startX+" "+startY+" "+0+" "+gun[startY][startX][i][0]+" "+gun[startY][startX][i][1]);
			}
			int res = -1;
			while(!queue.isEmpty()) {
				Node node = queue.poll();
//				System.out.println(node.x+" "+node.y+" "+node.cost+" "+node.gunx+" "+node.guny);
				if(node.x == goalX && node.y == goalY) {
					res = node.cost;
					break;
				}
				// •’Ê‚ÌˆÚ“®
				for(int i = 0; i < 4; i++) {
					int nx = node.x + move[i][0], ny = node.y + move[i][1];
					if(map[ny][nx] == 0) continue;
					if(costs[ny][nx][node.guny][node.gunx] < 0) {
						costs[ny][nx][node.guny][node.gunx] = node.cost + 1;
						queue.add(new Node(nx, ny, node.cost + 1,
								node.gunx, node.guny));
					}
					for(int j = 0; j < 4; j++) {
						int gy = gun[ny][nx][j][1], gx = gun[ny][nx][j][0];
						if(costs[ny][nx][gy][gx] < 0) {
							costs[ny][nx][gy][gx] = node.cost + 1;
							queue.add(new Node(nx, ny, node.cost + 1, gx, gy));
						}
					}
				}
				
				// •ÇˆÚ“®
				boolean isWall = false;
				for(int i = 0; i < 4; i++) {
					if(map[node.y + move[i][0]][node.x + move[i][1]] == 0)
						isWall = true;
				}
				if(isWall) {
					int nx = node.gunx, ny = node.guny;
					for(int j = 0; j < 4; j++) {
//						try{
							int gy = gun[ny][nx][j][1], gx = gun[ny][nx][j][0];
						if(costs[ny][nx][gy][gx] < 0) {
							costs[ny][nx][gy][gx] = node.cost + 1;
							queue.add(new Node(nx, ny, node.cost + 1, gx, gy));
						}
//						} catch(Exception e) {
//							System.out.println(node.x+" "+node.y+" "+node.cost+" "+
//									" "+node.gunx+" "+node.guny);
//						}
					}
				}
			}
			System.out.println(res == -1 ? "THE CAKE IS A LIE" : res);
		}
	}
	int[][] move = {{-1, 0},{0,-1},{1,0},{0,1}};
	static class Node implements Comparable<Node> {
		int cost;
		int x, y, gunx, guny;
//		int guntype;
		Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
		Node(int x, int y, int cost, int gunx, int guny) {
			this.x = x;
			this.y = y;
			this.cost = cost;
			this.gunx = gunx;
			this.guny = guny;
//			this.guntype = guntype;
		}
		public int compareTo(Node o) {
			return cost - o.cost;
		}
	}
}
