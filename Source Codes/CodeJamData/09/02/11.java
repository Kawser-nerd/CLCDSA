import java.io.*;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.util.Arrays;
public class B{
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("B-large.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("B-large.out"));
		int T = Integer.parseInt(in.readLine());
		for(int i = 1; i <= T; i++){
			out.write("Case #"+i+":\n");
			StringTokenizer getInfo = new StringTokenizer(in.readLine());
			int H = Integer.parseInt(getInfo.nextToken());
			int W = Integer.parseInt(getInfo.nextToken());
			int[][] map = new int[W][H];
			for(int y = 0; y < H; y++){
				getInfo = new StringTokenizer(in.readLine());
				for(int x = 0; x < W; x++){
					map[x][y] = Integer.parseInt(getInfo.nextToken());
				}
			}
			int[][] ans = new int[W][H];
			int count=0;
			for(int y = 0; y < H; y++){
				for(int x = 0; x < W-1; x++){
					count=go(map,ans,x,y,count);
					out.write((char)(ans[x][y]-1+'a')+" ");
				}
				count=go(map,ans,W-1,y,count);
				out.write((char)(ans[W-1][y]-1+'a')+"\n");
			}
		}
		out.close();
	}
	private static int go(int[][] map, int[][] ans, int x, int y, int count){
		if(ans[x][y]>0) return count;
		int min = map[x][y]-1;
		if(y>0) min=Math.min(min,map[x][y-1]);
		if(x>0) min=Math.min(min,map[x-1][y]);
		if(x<map.length-1) min=Math.min(min,map[x+1][y]);
		if(y<map[x].length-1) min=Math.min(min,map[x][y+1]);
		if(y>0 && map[x][y-1]==min){
			count=go(map,ans,x,y-1,count);
			ans[x][y] = ans[x][y-1];
			return count;
		}
		if(x>0 && map[x-1][y]==min){
			count=go(map,ans,x-1,y,count);
			ans[x][y] = ans[x-1][y];
			return count;
		}
		if(x<map.length-1 && map[x+1][y]==min){
			count=go(map,ans,x+1,y,count);
			ans[x][y] = ans[x+1][y];
			return count;
		}
		if(y<map[x].length-1 && map[x][y+1]==min){
			count=go(map,ans,x,y+1,count);
			ans[x][y] = ans[x][y+1];
			return count;
		}
		ans[x][y] = ++count;
		return count;
	}
}