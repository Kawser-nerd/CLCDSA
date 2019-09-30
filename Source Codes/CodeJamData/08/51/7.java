import java.util.*;

public class A {
	static final int SIZE = 6400;
	static final int OFFSET = 3200;
	static final int RIGHT = 0, UP = 1, LEFT = 2, DOWN = 3;
	static Scanner sc = new Scanner(System.in);
	static byte[][] filled;
	static byte[][] ver;
	static byte[][] hor;
	public static void main(String[] args){
		filled = new byte[SIZE][SIZE];
		ver = new byte[SIZE][SIZE];
		hor = new byte[SIZE][SIZE];
		
		int N = sc.nextInt();
		for(int caseID = 1; caseID <= N; caseID++){
			clear();
			
			int px = OFFSET;
			int py = OFFSET;
			int pdir = UP;
			
			int L = sc.nextInt();
			for(int i = 0; i < L; i++){
				String S = sc.next();
				int T = sc.nextInt();
				for(int j = 0; j < T; j++){
					for(char c : S.toCharArray()){
						if(c == 'F'){
							if(pdir == RIGHT){
								hor[py][px] = 1;
								px++;
							}
							else if(pdir == UP){
								ver[py][px] = 1;
								py++;
							}
							else if(pdir == LEFT){
								hor[py][px - 1] = 1;
								px--;
							}
							else if(pdir == DOWN){
								ver[py - 1][px] = 1;
								py--;
							}
						}
						else if(c == 'L'){
							pdir = (pdir + 1) % 4;
						}
						else if(c == 'R'){
							pdir = (pdir + 3) % 4;
						}
					}
				}
			}
			
			ArrayList<Integer> events = new ArrayList<Integer>();
			for(int y = 0; y < SIZE; y++){
				events.clear();
				for(int x = 0; x < SIZE; x++){
					if(ver[y][x] > 0){
						events.add(x);
					}
				}
				if(events.size() >= 4){
					for(int i = 1; i + 1 < events.size(); i += 2){
						int x1 = events.get(i);
						int x2 = events.get(i + 1);
						for(int x = x1; x < x2; x++){
							filled[y][x] = 1;
						}
					}
				}
			}
			for(int x = 0; x < SIZE; x++){
				events.clear();
				for(int y = 0; y < SIZE; y++){
					if(hor[y][x] > 0){
						events.add(y);
					}
				}
				if(events.size() >= 4){
					// System.out.println("SIZE: " + events.size());
					for(int i = 1; i + 1 < events.size(); i += 2){
						int y1 = events.get(i);
						int y2 = events.get(i + 1);
						for(int y = y1; y < y2; y++){
							filled[y][x] = 1;
						}
					}
				}
			}
			
			int cnt = 0;
			for(int y = 0; y < SIZE; y++){
				for(int x = 0; x < SIZE; x++){
					if(filled[y][x] > 0) cnt++;
				}
			}
			System.out.printf("Case #%d: %d%n", caseID, cnt);
		}
	}
	static void clear(){
		for(byte[] line : filled) Arrays.fill(line, (byte)0);
		for(byte[] line : ver) Arrays.fill(line, (byte)0);
		for(byte[] line : hor) Arrays.fill(line, (byte)0);
	}
}
