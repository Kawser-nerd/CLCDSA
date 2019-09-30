
import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;

public class A {
	static final int TOTAL = 10000;
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int caseNum = sc.nextInt();
		for(int caseID = 1; caseID <= caseNum; caseID++){
			new A().solveDataSet(caseID);
		}
	}
	int N;
	ArrayList<Int3D>[] x2Points;
	void solveDataSet(int caseID){
		N = sc.nextInt();
		x2Points = (ArrayList<Int3D>[])(new ArrayList<?>[TOTAL + 1]);
		for(int x = 0; x <= TOTAL; x++){
			x2Points[x] = new ArrayList<Int3D>();
		}
		for(int i = 0; i < N; i++){
			int x = sc.nextInt();
			int y = sc.nextInt();
			int z = sc.nextInt();
			x2Points[x].add(new Int3D(x, y, z));
		}
		
		int ans = 0;
		
		for(int z = 0; z <= TOTAL; z++){
			int cnt = 0;
			int[] yCnt = new int[TOTAL - z + 1];
			for(int x = 0; x <= TOTAL - z; x++){
				if(x > 0){
					cnt -= yCnt[TOTAL - z - (x - 1)];
				}
				for(Int3D p : x2Points[x]){
					if(p.z <= z && p.y <= TOTAL - z - x){
						yCnt[p.y]++;
						cnt++;
					}
				}

				ans = Math.max(cnt, ans);
			}
		}
		
		System.err.printf("Case #%d:%n", caseID);
		System.out.printf("Case #%d: %d%n", caseID, ans);
	}
}

class Int3D{
	int x, y, z;
	public Int3D(int x, int y, int z) {
		super();
		this.x = x;
		this.y = y;
		this.z = z;
	}
}
