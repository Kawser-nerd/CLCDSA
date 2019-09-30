import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

public class Solution {
	
	static String TASK = "XXX";
    static Scanner in;
	static PrintWriter out;
    
    static class Pair implements Comparable<Pair> {
    	public int x, y, z;
    	public long d;
    	public Pair(int xx, int yy, int zz, long dd) {
    		x = xx; y = yy; z = zz; d = dd;
    	}
    	public int compareTo(Pair p) {
    		if (d != p.d) {if (d < p.d) {return -1;} else return 1;}
    		if (x != p.x) {return x-p.x;}
    		if (y != p.y) {return y-p.y;}
    		return z-p.z;
    	}
    }

    static int n, m;
    static int[][] s, w, t;
    static long[][][] d;
    static boolean[][][] b;

    static long timeS(long time, int x, int y) {
    	/*
    	if (time < t[x][y]) {
    		
    		int time1 = time % (s[x][y] + w[x][y]);
    		if (time1 < s[x][y]) {
    			return time+1;
    		} else {
    			int time2 = s[x][y] + w[x][y] - time1 + time;
    			time2 = Math.min(time2, t[x][y]);
    			return time2+1;
    		}   

    	} else {
    		int time1 = time - t[x][y];
    		time1 = time1 % (s[x][y] + w[x][y]);
    		if (time1 < s[x][y]) {
    			return time+1;
    		} else {
    			int time2 = s[x][y] + w[x][y] - time1 + time;
    			return time2+1;
    		}
    	} */
    	long time1 = time-t[x][y] + (1+Math.max(0, (t[x][y] - time) / (s[x][y] + w[x][y]))) * (s[x][y] + w[x][y]);
    	time1 = time1 % (s[x][y] + w[x][y]);
    	if (time1 < s[x][y]) {return time+1;}
    	else {
    		return (s[x][y] + w[x][y]) - time1 + time + 1;
    	}
    }

    static long timeW(long time, int x, int y) {
    	/*if (time < t[x][y]) {
    		int time1 = time % (s[x][y] + w[x][y]);
    		if (time1 >= s[x][y]) {
    			return time+1;
    		} else {
    			int time2 = s[x][y] - time1 + time;
    			time2 = Math.min(time2, t[x][y]);
    			return time2+1;
    		}   
    		return time+1;

    	} else {
    		int time1 = time - t[x][y];
    		time1 = time1 % (s[x][y] + w[x][y]);
    		if (time1 >= s[x][y]) {
    			return time+1;
    		} else {
    			int time2 = s[x][y] - time1 + time;
    			return time2+1;
    		}
    	}
    	*/
    	long time1 = time-t[x][y] + (1+Math.max(0, (t[x][y] - time) / (s[x][y] + w[x][y]))) * (s[x][y] + w[x][y]);
    	time1 = time1 % (s[x][y] + w[x][y]);
    	if (time1 >= s[x][y]) {return time+1;}
    	else {
    		return (s[x][y]) - time1 + time + 1;
    	}
    }

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File(TASK+".in"));
		out = new PrintWriter(new File(TASK+".out"));

		int cas = in.nextInt();
		for (int c=1; c<=cas; c++) {

		n = in.nextInt();
		m = in.nextInt();
		s = new int[n][m];
		w = new int[n][m];
		t = new int[n][m];
		
		d = new long[n][m][4];
		b = new boolean[n][m][4];
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				s[n-i-1][j] = in.nextInt();
				w[n-i-1][j] = in.nextInt();
				t[n-i-1][j] = in.nextInt();
            	Arrays.fill(d[n-i-1][j], Long.MAX_VALUE);
            }
		}

		
		TreeSet<Pair> q = new TreeSet<Pair>();
		q.add(new Pair(0, 0, 0, 0));
		d[0][0][0] = 0;
		while (!q.isEmpty()) {
			Pair p = q.first();
			q.remove(p);
			b[p.x][p.y][p.z] = true;

//out.println(p.x + " " + p.y + " " + p.z + " d= " + d[p.x][p.y][p.z]);

			long time = d[p.x][p.y][p.z];
			
			if ((p.z & 1) == 1) {
				if (p.x < (n-1) && !b[p.x+1][p.y][p.z-1] && d[p.x+1][p.y][p.z-1] > time+2) {
					d[p.x+1][p.y][p.z-1] = time+2;
					q.add(new Pair(p.x+1, p.y, p.z-1, time+2));
				}
				if (!b[p.x][p.y][p.z-1] && d[p.x][p.y][p.z-1] > timeS(time, p.x, p.y)) {
					d[p.x][p.y][p.z-1] = timeS(time, p.x, p.y);
					q.add(new Pair(p.x, p.y, p.z-1, timeS(time, p.x, p.y)));
				}   					
			} else {
				if (p.x > 0 && !b[p.x-1][p.y][p.z+1] && d[p.x-1][p.y][p.z+1] > time+2) {
					d[p.x-1][p.y][p.z+1] = time+2;
					q.add(new Pair(p.x-1, p.y, p.z+1, time+2));
				}
				if (!b[p.x][p.y][p.z+1] && d[p.x][p.y][p.z+1] > timeS(time, p.x, p.y)) {
					d[p.x][p.y][p.z+1] = timeS(time, p.x, p.y);
					q.add(new Pair(p.x, p.y, p.z+1, timeS(time, p.x, p.y)));
				}   					
			}

			if ((p.z & 2) == 2) {
				if (p.y < (m-1) && !b[p.x][p.y+1][p.z-2] && d[p.x][p.y+1][p.z-2] > time+2) {
					d[p.x][p.y+1][p.z-2] = time+2;
					q.add(new Pair(p.x, p.y+1, p.z-2, time+2));
				}
				if (!b[p.x][p.y][p.z-2] && d[p.x][p.y][p.z-2] > timeW(time, p.x, p.y)) {
					d[p.x][p.y][p.z-2] = timeW(time, p.x, p.y);
					q.add(new Pair(p.x, p.y, p.z-2, timeW(time, p.x, p.y)));
				}   					
			} else {
				if (p.y > 0 && !b[p.x][p.y-1][p.z+2] && d[p.x][p.y-1][p.z+2] > time+2) {
					d[p.x][p.y-1][p.z+2] = time+2;
					q.add(new Pair(p.x, p.y-1, p.z+2, time+2));
				}
				if (!b[p.x][p.y][p.z+2] && d[p.x][p.y][p.z+2] > timeW(time, p.x, p.y)) {
					d[p.x][p.y][p.z+2] = timeW(time, p.x, p.y);
					q.add(new Pair(p.x, p.y, p.z+2, timeW(time, p.x, p.y)));
				}   					
			}
		}

		out.println("Case #"+c+": "+d[n-1][m-1][3]);

		}

		out.flush();
	}	
}
