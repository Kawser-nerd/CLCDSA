import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Watersheds {
	
	static int m[][];		// the latitude is here
	static char s[][];		// the solution is placed here
	static int H, W;
	static char color;
	static int dy[] = {-1, 0, 0, 1};
	static int dx[] = {0, -1, 1, 0};
	
	static void printM() {
		int i,j;
		for (i=0;i<H+2;i++) {
			for (j=0;j<W+2;j++) {
				System.out.print(m[i][j]+" ");
			}
			System.out.println();
		}
	}
	
	static void printS() {
		int i,j;
		for (i=0;i<H+2;i++) {
			for (j=0;j<W+2;j++) {
				System.out.print(s[i][j]);
			}
			System.out.println();
		}
	}
	
	// we check if the water can go from 1 to 2
	// we are sure that the two places will be neighbours so we don't check that here
	static boolean goes(int y1, int x1, int y2, int x2) {
		int i,j,k;
		int nx, ny;
		int smallest = 20000;
		
		for (i=0;i<4;i++) {
			ny = y1+dy[i];
			nx = x1+dx[i];
			
			if ((ny>=0)&&(ny<=H+1)&&(nx>=0)&&(nx<=W+1)) {
				smallest = Math.min(smallest, m[ny][nx]);
			}
		}
		
		if (smallest >= m[y1][x1]) {
			return false;
		} else {
			for (i=0;i<4;i++) {
				ny = y1+dy[i];
				nx = x1+dx[i];
				
				if ((ny>=0)&&(ny<=H+1)&&(nx>=0)&&(nx<=W+1)) {
					if (m[ny][nx] == smallest) {
					
						if ((ny == y2)&&(nx == x2)) {
							return true;
						} else {
							return false;
						}
					
					}
				}
				
			}
		}
		
		return true;
	}
	
	static void spread(int y, int x) {
		// first we check if some free neighbouring square has it's way here
		int i,j,k;
		int nx, ny;
		s[y][x] = color;
		
		//System.out.println("SPREAD: "+y+" "+x);
		
		// now we see where the water goes from here
		
		for (i=0;i<4;i++) {
			ny = y+dy[i];
			nx = x+dx[i];
			
			//System.out.println("NEW COORDINATES: "+ny+" "+nx+" "+goes(y, x, ny, nx));
			
			if ((ny>=0)&&(ny<=H+1)&&(nx>=0)&&(nx<=W+1)) {
				if ((goes(y, x, ny, nx) == true)&&(s[ny][nx] == '.')) {
					spread(ny, nx);
					break;
				}
			}
			
		}
		
		for (i=0;i<4;i++) {
			ny = y+dy[i];
			nx = x+dx[i];
			
			//System.out.println("LA: "+y+" "+dy[i]+" "+x+" "+dx[i]);
			
			if ((ny>=0)&&(ny<=H+1)&&(nx>=0)&&(nx<=W+1)) {
				if ((goes(ny, nx, y, x) == true)&&(s[ny][nx] == '.')) {
					spread(ny, nx);
				}
			}
			
		}
		
		
		
	}
	
	public static void main(String[] args) throws Exception {
		int i,j,k;
		int T;
		String line;
		
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
		
		StringTokenizer st;
		line = br.readLine();
		st = new StringTokenizer(line);
		T = Integer.parseInt(st.nextToken());
		
		for (i=1;i<=T;i++) {
			line = br.readLine();
			st = new StringTokenizer(line);
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			
			m = new int[H+2][W+2];
			s = new char[H+2][W+2];
			
			for (j=0;j<=H+1;j++) {
				for (k=0;k<=W+1;k++) {
					m[j][k] = 20000;
				}
			}
			
			for (j=1;j<=H;j++) {
				for (k=1;k<=W;k++) {
					// this means empty square
					s[j][k] = '.';
				}
			}
			
			for (j=0;j<=H+1;j++) {
				s[j][0] = '#';
				s[j][W+1] = '#';
			}
			
			for (j=0;j<=W+1;j++) {
				s[0][j] = '#';
				s[H+1][j] = '#';
			}
			
			for (j=0;j<H;j++) {
				// we read each row
				line = br.readLine();
				st = new StringTokenizer(line);
				
				for (k=0;k<W;k++) {
					m[j+1][k+1] = Integer.parseInt(st.nextToken());
				}
				
			}
			
			/*
			printM();
			printS();
			*/
			
			color = 'a';
			
			for (j=1;j<=H;j++) {
				for (k=1;k<=W;k++) {
					// if we haven't worked out this square we do that now
					if (s[j][k] == '.') {
						
						// we use the color
						
						spread(j, k);
						
						color++;
						
					}
				}
			}
			
			out.println("Case #"+i+":");
			
			// printS();
			
			for (j=1;j<=H;j++) {
				for (k=1;k<=W;k++) {
					if (k < W) {
						out.print(s[j][k]+" ");
					} else {
						out.println(s[j][k]);
					}
				}
			}
			
		}
		
		out.close();
		System.exit(0);	
		
	}
	
}

