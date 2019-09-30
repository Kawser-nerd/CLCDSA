import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

/**
 * http://abc008.contest.atcoder.jp/tasks/abc008_4
 */
public class Main {
	
	private static final List<Pos> posList = new ArrayList<Pos>();
	private static final Map<String,Integer> dp = new HashMap<>();

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		final int W = sc.nextInt();
		final int H = sc.nextInt();
		final int N = sc.nextInt();
		for(int i=0; i<N; i++){
			posList.add(new Pos(sc.nextInt(),sc.nextInt()));
		}
		sc.close();
		
		System.out.println( getMaxCount( 1, 1, W, H));
	}
	
	private static int getMaxCount(final int sx, final int sy, final int ex, final int ey){
		
		if( sx<1 || sy<1 || ey<sy || ex<sx){
			return 0;
		}
		
		String key = String.format("%d.%d.%d.%d", sx,sy,ex,ey);
		
		if(!dp.containsKey(key)){
			int maxCount = 0;
			final int count = (ex - sx) + (ey - sy) + 1;
			for(Pos pos: posList){
				if( sx <= pos.x && pos.x <= ex && sy <= pos.y && pos.y <= ey){
					maxCount = Math.max(maxCount, 
							count + 
							getMaxCount(sx, sy, pos.x-1, pos.y-1) +
							getMaxCount(pos.x+1, sy, ex,  pos.y-1) +
							getMaxCount(sx, pos.y+1, pos.x-1, ey) +
							getMaxCount(pos.x+1, pos.y+1, ex, ey));
				}
			}
			dp.put(key, maxCount);
		}
		
		// System.out.println( String.format("%d,%d-%d,%d: %d", sx,sy,ex,ey, dp[sx][sy][ex][ey]));
		
		return dp.get(key);
		
	}
	
	private static class Pos{
		int x;
		int y;
		Pos(final int x, final int y){
			this.x = x;
			this.y = y;
		}
	}

}