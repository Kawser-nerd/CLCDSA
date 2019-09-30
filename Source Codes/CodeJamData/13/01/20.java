import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

public class A{
	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int caze, T, n=4;
	int[][] a;

	void run(){
		T=sc.nextInt();
		sc.nextLine();
		for(caze=1; caze<=T; caze++){
			a=new int[n][n];
			for(int j=0; j<n; j++){
				String s=sc.next();
				for(int i=0; i<n; i++){
					char c=s.charAt(i);
					if(c=='.'){
						a[j][i]=0;
					}else if(c=='X'){
						a[j][i]=1;
					}else if(c=='O'){
						a[j][i]=2;
					}else{
						a[j][i]=3;
					}
				}
			}
			solveSmall();
		}
	}

	void solveSmall(){
		boolean empty=false;
		int win=0;
		for(int j=0; j<n; j++){
			for(int i=0; i<n; i++){
				empty|=a[j][i]==0;
				win=max(win, check(i, j, 0, 1));
				win=max(win, check(i, j, 1, 0));
				win=max(win, check(i, j, 1, 1));
				win=max(win, check(i, j, -1, 1));
			}
		}
		if(win==1){
			answer("X won");
		}else if(win==2){
			answer("O won");
		}else if(empty){
			answer("Game has not completed");
		}else{
			answer("Draw");
		}
	}

	int check(int x, int y, int dx, int dy){
		int[] count=new int[4];
		for(; x>=0&&x<n&&y>=0&&y<n; x+=dx, y+=dy){
			count[a[y][x]]++;
		}
		if(count[1]==4||count[1]==3&&count[3]==1){
			return 1;
		}
		if(count[2]==4||count[2]==3&&count[3]==1){
			return 2;
		}
		return 0;
	}

	void solveLarge(){

	}

	void answer(String s){
		println("Case #"+caze+": "+s);
	}

	void println(String s){
		System.out.println(s);
	}

	void print(String s){
		System.out.print(s);
	}

	void debug(Object... os){
		System.err.println(deepToString(os));
	}

	public static void main(String[] args){
		new A().run();
	}
}
