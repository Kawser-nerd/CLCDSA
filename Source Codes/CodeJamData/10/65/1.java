import java.util.*;
import java.io.*;
import java.math.*;

public class Solution {
	Scanner sc;
	PrintWriter pw;
	int caseCnt, caseNum;
	
	int N, R;
	int[] x, y;
	
	void inputData() throws Exception  {
		N = sc.nextInt();
		R = sc.nextInt();
		x = new int[N];
		y = new int[N];
		for (int i=0; i < N; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
		}
	}
	
	int res;
	
	double myAtan2(int dy, int dx) {
		if (dx == 0) return (dy > 0 ? Math.PI/2 : -Math.PI/2);
		if (dx > 0) return Math.atan(dy / (double)dx);
		if (dy < 0) return Math.atan(dy / (double)dx) - Math.PI;
		return Math.atan(dy / (double)dx) + Math.PI; 
	}
	
	int go(double angle, double distLeft, int curX, int curY) {
		double minRotate = 100.0;
		double minDist = 1e100;
		double resAngle = -100.0;
		int nextX = -1, nextY = -1;
		
		for (int i=0; i < N; i++) {
			if (x[i] == curX && y[i] == curY) continue;
			double dist = Math.sqrt((curY - y[i]) * (curY - y[i]) + (curX - x[i]) * (curX - x[i]));
			if (dist > distLeft - 1e-9) continue;
			
			double nextAngle = myAtan2(y[i] - curY, x[i] - curX);
			
			double diff = nextAngle - angle;
			while (diff >= 2 * Math.PI + 1e-9) diff -= 2 * Math.PI;
			while (diff < -1e-9) diff += 2 * Math.PI;
			
			if (diff < minRotate - 1e-9 || diff < minRotate + 1e-9 && dist > minDist) {
				minRotate = diff;
				minDist = dist;
				resAngle = nextAngle;
				nextX = x[i];
				nextY = y[i];
			}
		}
		return (minDist < 1e50 ? go(resAngle, distLeft - minDist, nextX, nextY) + 1 : 0);
	}
	
	void solveProblem() {
		res = 0;
		
		for (double r = 0.0; r <= R + 1e-9; r += 0.5) {
			//System.out.println(r + " " + go(-Math.PI, r, 0, 0));
			res = Math.max(res, go(-Math.PI, r, 0, 0));
		}
	}
	
	void outputData() {
		pw.print("Case #" + caseNum + ": ");
		
		pw.print(res);
		
		pw.println();
	}
	
	public void go() throws Exception {
		sc = new Scanner(new FileReader("input.txt"));
		pw = new PrintWriter(new FileWriter("output.txt"));
		
		caseCnt = sc.nextInt();
		for (caseNum=1; caseNum <= caseCnt; caseNum++) {
			inputData();
			solveProblem();
			outputData();
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new Solution()).go();
	}
}