
import java.io.*;
import java.util.*;

public class CodeJam2012_Q_D {

	public int calc(int H, int W, int D, String[] mirror) {
		int[][] seen = new int[D*2+1][D*2+1];
		int sx=0,sy=0;
		for(int i=0; i<D*2+1; i++)
			Arrays.fill(seen[i], -1);
		
		boolean[][] m = new boolean[H][W];
		for(int i=0; i<H; i++) {
			if(mirror[i].indexOf('X')>=0) {
				sx = mirror[i].indexOf('X');
				sy = i;
			}
			for(int j=0; j<W; j++) {
				if(mirror[i].charAt(j)=='#') m[i][j] = true;
			}
		}
		
		for(int y=-D; y<=D; y++) {
			for(int x=-D; x<=D; x++) {
				if(y*y+x*x>D*D || (x==0 && y==0)) {
					seen[y+D][x+D] = 0;
				}
				if(seen[y+D][x+D]!=-1) continue;
				
				int gcd = Math.abs(gcd(x, y));
				int dx = x/gcd;
				int dy = y/gcd;
				int unit = dx*dy==0? 2:Math.abs(dx*dy)*2;
				int cellx = sx;
				int celly = sy;
				int lx = unit/2;
				int ly = unit/2;
				int pathMax = x==0? y*unit/dy : x*unit/dx;
				int pathCnt = 0;
				while(pathCnt<pathMax) {
					pathCnt++;
					lx += dx;
					ly += dy;
					int nx, ny, ndx, ndy, nlx, nly;
					if(celly==sy && cellx==sx && ly==unit/2 && lx==unit/2) {
						//return to start point
						seen[y+D][x+D]=1;
						dx = x/gcd;
						dy = y/gcd;
						for(int d=1; -D<=y+d*dy && y+d*dy<=D && -D<=x+d*dx && x+d*dx<=D; d++) {
							seen[y+d*dy+D][x+d*dx+D]=0;
						}
						break;
					}
					nx=cellx;
					ny=celly;
					ndx=dx;
					ndy=dy;
					nlx=lx;
					nly=ly;
					if(ly%unit==0 && lx%unit==0) {
						if(m[celly + (dy>0?1:-1)][cellx + (dx>0?1:-1)]) {
							//hit a corner
							if(!m[celly + (dy>0?1:-1)][cellx] && !m[celly][cellx + (dx>0?1:-1)]) break;
							
							//reflected with horizontal mirror
							if(m[celly + (dy>0?1:-1)][cellx]) {
								ndy = -dy;
							} else {
								ny = celly+(dy>0?1:-1);
								nly = ly==0?unit:0;
							}
							
							//reflected with vertical mirror
							if(m[celly][cellx + (dx>0?1:-1)]) {
								ndx = -dx;
							} else {
								nx = cellx+(dx>0?1:-1);
								nlx = lx==0?unit:0;
							}
							
						} else {
							nx = cellx+(dx>0?1:-1);
							ny = celly+(dy>0?1:-1);
							nlx = lx==0?unit:0;
							nly = ly==0?unit:0;
						}
					} else if(ly%unit==0) {
						//reflected with horizontal mirror
						if(m[celly + (dy>0?1:-1)][cellx]) {
							ndy = -dy;
						} else {
							ny = celly+(dy>0?1:-1);
							nly = ly==0?unit:0;
						}

					} else if(lx%unit==0) {
						//reflected with vertical mirror
						if(m[celly][cellx + (dx>0?1:-1)]) {
							ndx = -dx;
						} else {
							nx = cellx+(dx>0?1:-1);
							nlx = lx==0?unit:0;
						}
					}
					cellx=nx;
					celly=ny;
					dx=ndx;
					dy=ndy;
					lx=nlx;
					ly=nly;
				}
				if(seen[y+D][x+D]==-1) seen[y+D][x+D]=0;
			}
		}
		
		int cnt=0;
		for(int[] s1 : seen)
			for(int s2 : s1)
				cnt += s2;
		return cnt;
	}
	
	public int gcd(int a, int b) {
		return b==0? a : gcd(b, a%b);
	}
	
	public static void main(String[] args) {
		try{
//			(new CodeJam2012_Q_D()).exec("D-small-attempt0.in", "2012_Q_D-small.out");
			(new CodeJam2012_Q_D()).exec("D-large.in", "2012_Q_D-large.out");
			}catch(Exception ex) {
				
			}
	}

	public final void exec(String inFileName, String outFileName) throws Exception{
		BufferedReader	inReader	= new BufferedReader(new FileReader(inFileName));
		PrintWriter		outWriter	= new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));
		int caseNums=0;
		caseNums = Integer.parseInt(inReader.readLine());
		
		for(int i=0; i<caseNums; i++) {
			String[] input = inReader.readLine().split(" ");
			int H = Integer.valueOf(input[0]);
			int W = Integer.valueOf(input[1]);
			int D = Integer.valueOf(input[2]);
			String[] mirror = new String[H];
			for(int j=0; j<H; j++) {
				mirror[j] = inReader.readLine();
			}
			int outStr = calc(H, W, D, mirror);

			String fmtOutStr="Case #" + (i+1) + ": " + outStr;	
			outWriter.println(fmtOutStr);
			System.out.println(fmtOutStr);
		}
		System.out.println(caseNums + " cases complete");

		outWriter.close();
		inReader.close();
	}
}
