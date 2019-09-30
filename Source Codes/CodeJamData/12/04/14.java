package j2012qualifier;

import java.awt.Point;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class D {
	public static String inputDirectory="src/j2012qualifier/";
	public static String inputFile="D.in";
	public static String outputFile="D.out";
	public static PrintWriter output;
	public static char[][] room;
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s=new Scanner(new File(inputDirectory + inputFile));
		output=new PrintWriter(new File(inputDirectory + outputFile));
		int cases = s.nextInt();
		//size of each square
		s.nextLine();
		for(int Case=1;Case<=cases;Case++){
			int H = s.nextInt();
			int W = s.nextInt();
			int D = s.nextInt();
			s.nextLine();
			room = new char[H][W];
			int x=0, y=0;
			for(int i=0;i<H;i++){
				String line = s.nextLine();
				for(int j=0;j<W;j++){
					room[i][j] = line.charAt(j);
					if (room[i][j] == 'X') {
						x = j;
						y = i;
					}
				}
			}
			int count = 0;
			Set<String> used = new HashSet<String>();
			for(int i=-D; i<=D ;i++) {
				for(int j=-D; j<=D; j++) {
					int dx = j;
					int dy = i;
					if (dx == 0 && dy == 0) continue;
					if (dx == 0) dy = (int)(dy / Math.sqrt(dy * dy));
					if (dy == 0) dx = (int)(dx / Math.sqrt(dx * dx));
					if(i != 0 && j!=0) {
						int gcd = GCD(i, j);
						gcd = gcd < 0 ? -gcd : gcd;
						dx = j / gcd;
						dy = i / gcd;
					}
					String key = dx+","+dy;
					if (used.contains(key))continue;
					used.add(key);
					int lcm = dx*dy;
					if ( dx == 0) {
						lcm = dy;
					} else if(dy == 0){
						lcm = dx;
					}
					lcm = lcm < 0 ? -lcm : lcm;
					int startX = (2*x+1)*lcm;
					int startY = (2*y+1)*lcm;
					if(castRay(lcm, D * lcm * 2, startX, startY, dx, dy, startX, startY)) {
						count++;
					}
				}
			}

            output.printf("Case #%d: %d\n", Case, count);
		}
		output.flush();
	}
	
	public static int GCD(int a, int b)
	{
	   if (b == 0) return a;
	   return GCD(b, a % b);
	}
	
	public static boolean castRay(int lcm, double D, int x, int y, int dx, int dy, int gx, int gy) {
		//out(D+ " : ("+x+","+y+")  <"+dx+","+dy+">");
		if (D<=0) {
			return false;
		}
		int xSteps=1000, ySteps=1000;
		if (dx > 0) {
			xSteps = ((x / lcm) * lcm + lcm - x) / dx;
		} else if(dx < 0) {
			xSteps = (((x - 1) / lcm) * lcm - x) / dx;
		}
		if (dy > 0) {
			ySteps = ((y / lcm) * lcm + lcm - y) / dy;
		} else if(dy < 0) {
			ySteps = (((y - 1) / lcm) * lcm - y) / dy;
		}
		int steps = Math.min(xSteps, ySteps);
		double distance = steps * Math.sqrt(dx*dx + dy*dy);
		if (distance > D) {
			return false;
		}
		int newX = x+dx*steps;
		int newY = y+dy*steps;
		if (newX == gx && newY == gy) {
			return true;
		}
		
		//we are on a vertical line
		boolean onVertical = (newX %(2*lcm) == 0);
		boolean onHorizontal = (newY %(2*lcm) == 0);
		int gridY = newY / (2 * lcm);
		int gridX = newX / (2 * lcm);
		int newDx = dx;
		int newDy = dy;
		
		if (onVertical && onHorizontal) {
			int tX = (dx < 0) ? gridX - 1 : gridX;
			int tY = (dy < 0) ? gridY - 1 : gridY;
			int cX = (tX == gridX) ? gridX - 1 : gridX;
			int cY = (tY == gridY) ? gridY - 1 : gridY;
			if(room[tY][tX] == '#') {
				if(room[tY][cX] != '#' && room[cY][tX] != '#') {
					//light destroyed
					return false;
				}
				if (room[tY][cX] == '#'){
					newDy = -dy;
				}
				if (room[cY][tX] == '#'){
					newDx = -dx;
				}
			}
		} else if(onVertical) {
			gridX += (dx < 0) ? -1 : 0;
			if(room[gridY][gridX] == '#') {
				newDx = -dx;
			}
		} else if(onHorizontal) {
			gridY += (dy < 0) ? -1 : 0;
			if(room[gridY][gridX] == '#') {
				newDy = -dy;
			}
		}
		return castRay(lcm, D - distance, newX, newY, newDx, newDy, gx, gy);
	}
	
	public static void out(String s){
		output.println(s);
		System.out.println(s);
	}
}
