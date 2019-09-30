import java.util.*;
public class b{
	public static int[] dx = {-1, 0, 1, 0};
	public static int[] dy = {0, 1, 0, -1};
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int cases = br.nextInt();
		for(int c = 0;c<cases;c++){
			int h = br.nextInt();
			int rs = br.nextInt();
			int cs = br.nextInt();
			int[][] floor = new int[rs][cs];
			int[][] ciel = new int[rs][cs];
			for(int i = 0;i<rs;i++){
				for(int j = 0;j<cs;j++){
					ciel[i][j] = br.nextInt();
				}
			}
			for(int i = 0;i<rs;i++){
				for(int j = 0;j<cs;j++){
					floor[i][j] = br.nextInt();
				}
			}
			int[][] seen = new int[rs][cs];
			for(int i = 0;i<rs;i++){
				Arrays.fill(seen[i], -1000000000);
			}
			PriorityQueue<state> qu = new PriorityQueue<state>();
			qu.add(new state(0, 0, h));
			seen[0][0] = h;
			while(!qu.isEmpty()){
				state cur = qu.poll();
				if(cur.r == rs-1 && cur.c == cs-1){
					continue;
				}
				for(int i = 0;i<dx.length;i++){
					int nr = cur.r+dx[i];
					int nc = cur.c+dy[i];
					if(nr <0 || nc < 0 || nr >= rs || nc >= cs){
						continue;
					}
					int nciel = ciel[nr][nc];
					int nflor = floor[nr][nc];
					if(nciel-nflor >= 50 && nciel-floor[cur.r][cur.c] >= 50 && ciel[cur.r][cur.c]-nflor >= 50){
						if(cur.w == h && nciel-cur.w >= 50 && seen[nr][nc] < cur.w){
							seen[nr][nc] = cur.w;
							qu.add(new state(nr, nc, cur.w));
						}
						int tneed = 50-(nciel-cur.w);
						int nw = cur.w;
						if(tneed > 0)
							nw-=tneed;
						if(nw-floor[cur.r][cur.c] >= 20){
							nw-=10;
						}
						else{
							nw-=100;
						}
						if(seen[nr][nc] < nw){
							seen[nr][nc] = nw;
							qu.add(new state(nr, nc, nw));
						}
					}
				}
			}
			System.out.println("Case #"+(c+1)+": "+(h-seen[rs-1][cs-1])/10.0);
		}
	}
	public static class state implements Comparable<state>{
		int r, c, w;
		public state(int a, int b, int d){
			r = a;
			c = b;
			w = d;
		}
		public int compareTo(state o){
			return w-o.w;
		}
	}
}