import java.util.*;

public class A {
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args){
		int N = sc.nextInt();
		for(int caseID = 1; caseID <= N; caseID++){
			int n = sc.nextInt();
			long A = sc.nextLong();
			long B = sc.nextLong();
			long C = sc.nextLong();
			long D = sc.nextLong();
			long x0 = sc.nextLong();
			long y0 = sc.nextLong();
			long M = sc.nextLong();
			
			int[][] table = new int[3][3];
			long X = x0;
			long Y = y0;
			table[(int)(X % 3)][(int)(Y % 3)]++;
			for(int i = 1; i < n; i++){
				X = (A * X + B) % M;
				Y = (C * Y + D) % M;
				table[(int)(X % 3)][(int)(Y % 3)]++;
			}
			
			long count = 0;
			for(int x1 = 0; x1 < 3; x1++){
				for(int y1 = 0; y1 < 3; y1++){
					if(table[x1][y1] == 0) continue;
					long c1 = table[x1][y1];
					table[x1][y1]--;
					for(int x2 = 0; x2 < 3; x2++){
						for(int y2 = 0; y2 < 3; y2++){
							if(table[x2][y2] == 0) continue;
							long c2 = table[x2][y2];
							table[x2][y2]--;
							for(int x3 = 0; x3 < 3; x3++){
								for(int y3 = 0; y3 < 3; y3++){
									long c3 = table[x3][y3];
									if((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0){
										count += c1 * c2 * c3;
									}
								}
							}
							table[x2][y2]++;
						}
					}
					table[x1][y1]++;
				}
			}
			count /= 6;
			System.out.printf("Case #%d: %d%n", caseID, count);
		}
	}
}
