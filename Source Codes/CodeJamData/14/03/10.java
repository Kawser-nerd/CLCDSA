package con2014Q;

import java.io.*;
import java.util.*;

public class C {
	
	private static final String islarge = "-large";
	private static final String fileName = "results/con2014Q/"+C.class.getSimpleName().toLowerCase()+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	static final String IMPOSSIBRU = "Impossible";
	static final char CLICK = 'c', BOMB = '*', SPACE = '.';
	private void solve() {
		int R = in.nextInt(),
			C = in.nextInt(),
			M = in.nextInt();
		char[][] res = new char[R][C];
		// first handle some simple straightforward cases
		if(M==0){
			changeAll(SPACE, res);
			res[0][0]=CLICK;
			printRes(res, M);
			return;			
		}
		if(R*C==M+1){ // possible if you click the one free point
			changeAll(BOMB, res);
			res[0][0]=CLICK;
			printRes(res, M);
			return;
		}
		if(R*C<=M){ // impossible if all fields are mines (should never be the case according to specs)
			throw new RuntimeException();
//			impossibru();
//			return;
		}
		if(R==1 || C==1){ // case only one column
			changeAll(SPACE,res);
			res[0][0]=CLICK;
			if(R==1){
				for(int c=1;c<=M;c++){
					res[R-1][C-c]=BOMB;
				}
			}else{
				for(int r=1;r<=M;r++){
					res[R-r][C-1]=BOMB;
				}				
			}
			printRes(res,M);
			return;
		}
		int noBomb = (R*C)-M;
		if(noBomb<4 || noBomb==5 || noBomb == 7){
			impossibru();
			return;
		}
		if(noBomb%2 == 0){ // snake style, even can always be inserted
			changeAll(BOMB, res);
			res[0][1]=res[1][0]=res[1][1]=SPACE;
			noBomb-=4;
			// snakestyle rest
			for(int c=2;c<C && noBomb > 0;c++){
				res[0][c]=res[1][c]=SPACE;
				noBomb-=2;
			}
			for(int r=2;r<R && noBomb > 0;r++){
				res[r][0]=res[r][1]=SPACE;
				noBomb-=2;
			}
			// all other bombs will always fit in resting window
			for(int r=2;r<R && noBomb > 0;r++){
				for(int c=2;c<C && noBomb > 0;c++){
					res[r][c]=SPACE;
					noBomb--;
				}
			}
			res[0][0]=CLICK;
			printRes(res,M);
			return;
		}
		if(R==2 || C==2){ // odd and only 2 cols/rows is not possible
			impossibru();
			return;
		}
		// else always possible I guess
		changeAll(BOMB,res);
		res[0][0]=CLICK;
		res[0][1]=res[0][2]=SPACE;
		res[1][0]=res[1][1]=res[1][2]=SPACE;
		res[2][0]=res[2][1]=res[2][2]=SPACE;
		noBomb-=9;
		// snakestyle rest
		for(int c=3;c<C && noBomb > 0;c++){
			res[0][c]=res[1][c]=SPACE;
			noBomb-=2;
		}
		for(int r=3;r<R && noBomb > 0;r++){
			res[r][0]=res[r][1]=SPACE;
			noBomb-=2;
		}
		for(int c=3;c<C && noBomb > 0;c++){
			res[2][c]=SPACE;
			noBomb--;
		}
		// all other bombs will always fit in resting window
		for(int r=3;r<R && noBomb > 0;r++){
			for(int c=2;c<C && noBomb > 0;c++){
				res[r][c]=SPACE;
				noBomb--;
			}
		}
		printRes(res,M);
	}
		
	static void changeAll(char val, char[][]res){
		for(int r=0;r<res.length;r++){
			for(int c=0;c<res[r].length;c++){
				res[r][c]=val;
			}
		}
	}
	
	static void impossibru(){
		out.println(IMPOSSIBRU);
	}

	static void printRes(char[][] res, int M){
		//testReveal(res,M);
		int a_found = 0;
		for(int r=0;r<res.length;r++){
			for(int c=0;c<res[r].length;c++){
				if(res[r][c]==BOMB)M--;
				else if(res[r][c]==CLICK)a_found++;
				out.print(res[r][c]);				
			}
			out.println();
		}
		if(M!=0)throw new RuntimeException("wrong amount of bombs");
		if(a_found!=1)throw new RuntimeException("no click");
	}
	
	static boolean hasBombNbs(int r, int c, char[][]res){
		if(r>0 && res[r-1][c]==BOMB)return true;
		if(r>0 && c+1<res[r].length && res[r-1][c+1]==BOMB)return true;
		if(c+1<res[r].length && res[r][c+1]==BOMB)return true;
		if(r+1<res.length && c+1<res[r].length && res[r+1][c+1]==BOMB)return true;
		if(r+1<res.length && res[r+1][c]==BOMB)return true;
		if(r+1<res.length && c>0 && res[r+1][c-1]==BOMB)return true;
		if(c>0 && res[r][c-1]==BOMB)return true;
		if(r>0 && c>0 && res[r-1][c-1]==BOMB)return true;
		return false;
	}

	static boolean isValid(int r, int c, char[][]res){
		return r>=0 && r<res.length && c>=0 && c<res[r].length;
	}
	
	static void testReveal(char[][]res,int M){
		boolean[][]done = new boolean[res.length][res[0].length];
		int total = 0;
		Stack<int[]> stack = new Stack<int[]>();
		if(res[0][0]!=CLICK)throw new RuntimeException();
		done[0][0]=true;
		total++;
		if(!hasBombNbs(0, 0, res))
			stack.add(new int[]{0,0});
		while(!stack.isEmpty()){
			int[] cur = stack.pop();
			// do 8 directions
			// N
			if(isValid(cur[0]+1, cur[1], res) && !done[cur[0]+1][cur[1]]){
				done[cur[0]+1][cur[1]]=true;total++;
				if(!hasBombNbs(cur[0]+1, cur[1], res))stack.add(new int[]{cur[0]+1,cur[1]});
			}
			// NE
			if(isValid(cur[0]+1, cur[1]+1, res) && !done[cur[0]+1][cur[1]+1]){
				done[cur[0]+1][cur[1]+1]=true;total++;
				if(!hasBombNbs(cur[0]+1, cur[1]+1, res))stack.add(new int[]{cur[0]+1,cur[1]+1});
			}
			// E
			if(isValid(cur[0], cur[1]+1, res) && !done[cur[0]][cur[1]+1]){
				done[cur[0]][cur[1]+1]=true;total++;
				if(!hasBombNbs(cur[0], cur[1]+1, res))stack.add(new int[]{cur[0],cur[1]+1});
			}
			// SE
			if(isValid(cur[0]-1, cur[1]+1, res) && !done[cur[0]-1][cur[1]+1]){
				done[cur[0]-1][cur[1]+1]=true;total++;
				if(!hasBombNbs(cur[0]-1, cur[1]+1, res))stack.add(new int[]{cur[0]-1,cur[1]+1});
			}
			// S
			if(isValid(cur[0]-1, cur[1], res) && !done[cur[0]-1][cur[1]]){
				done[cur[0]-1][cur[1]]=true;total++;
				if(!hasBombNbs(cur[0]-1, cur[1], res))stack.add(new int[]{cur[0]-1,cur[1]});
			}
			// SW
			if(isValid(cur[0]-1, cur[1]-1, res) && !done[cur[0]-1][cur[1]-1]){
				done[cur[0]-1][cur[1]-1]=true;total++;
				if(!hasBombNbs(cur[0]-1, cur[1]-1, res))stack.add(new int[]{cur[0]-1,cur[1]-1});
			}
			// W
			if(isValid(cur[0], cur[1]-1, res) && !done[cur[0]][cur[1]-1]){
				done[cur[0]][cur[1]-1]=true;total++;
				if(!hasBombNbs(cur[0], cur[1]-1, res))stack.add(new int[]{cur[0],cur[1]-1});
			}
			// NW
			if(isValid(cur[0]+1, cur[1]-1, res) && !done[cur[0]+1][cur[1]-1]){
				done[cur[0]+1][cur[1]-1]=true;total++;
				if(!hasBombNbs(cur[0]+1, cur[1]-1, res))stack.add(new int[]{cur[0]+1,cur[1]-1});
			}
		}
		if(total!=(res.length*res[0].length)-M)
			System.err.println("testReveal: "+total+" => "+res.length);
			//throw new RuntimeException("testReveal: "+total+" => "+res.length);
	}

	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= tests; t++) {
			out.println("Case #" + t + ":");
			new C().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
