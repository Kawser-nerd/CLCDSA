
import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;

public class C {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int caseNum = sc.nextInt();
		for(int caseID = 1; caseID <= caseNum; caseID++){
			new C().solveDataSet(caseID);
		}
	}
	int R;
	int C;
	int[] values;
	int[] masks;
	void solveDataSet(int caseID){
		R = sc.nextInt();
		C = sc.nextInt();
		values = new int[R * C];
		for(int i = 0; i < R * C; i++){
			values[i] = sc.nextInt();
		}
		masks = new int[R * C];
		for(int i = 0; i < R * C; i++){
			for(int j = 0; j < R * C; j++){
				int ri = getRow(i);
				int ci = getCol(i);
				int rj = getRow(j);
				int cj = getCol(j);
				if(abs(ri - rj) <= 1 && abs(ci - cj) <= 1){
					masks[i] |= 1 << j;
				}
			}
		}
		int ans = -1;
		X: for(int x = 0; x < 1 << (R * C); x++){
			for(int i = 0; i < R * C; i++){
				if(values[i] != Integer.bitCount(x & masks[i])){
					continue X;
				}
			}
			int cnt = 0;
			for(int i = 0; i < R * C; i++){
				if(getRow(i) == R / 2){
					cnt += (x >> i) & 1;
				}
			}
			ans = Math.max(cnt, ans);
		}
		System.err.printf("Case #%d: %d%n", caseID, ans);
		System.out.printf("Case #%d: %d%n", caseID, ans);
	}
	int getRow(int id){
		return id / C;
	}
	int getCol(int id){
		return id % C;
	}
}
