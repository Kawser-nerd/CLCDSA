//~ 16:33:40
import java.util.*;
import java.io.*;

public class CChess{
	public static void main(String[] args){
		if(args.length<1){
			System.out.println("Usage: <fnIn>");
		}
		String fn = args[0];
		String fnOut = toFnOut(fn);
		try{
			BufferedReader br = new BufferedReader(new FileReader(fn));
			BufferedWriter bw = new BufferedWriter(new FileWriter(fnOut));
			String line = null;
			int NCase = Integer.valueOf(br.readLine().trim());
			long stime = System.currentTimeMillis();
			for(int icase=0;icase<NCase;icase++){
				int[] p = toIntArray(br.readLine());
				String[] lines = new String[p[0]];
				for(int i=0;i<lines.length;i++){
					lines[i] = br.readLine();
				}
				String buf = process(lines,p[0],p[1]);
				String out = "Case #"+(icase+1)+": "+buf;
				bw.write(out,0,out.length());
				bw.newLine();
				long ctime = System.currentTimeMillis();
				System.out.println(String.format("--- Done: #%2d,%3.0fs, ends in:%2.1fm",(icase+1),(ctime-stime)*0.001,(ctime-stime)*0.001/60*NCase/(icase+1)));
			}
			br.close();
			bw.close();
		}catch(IOException ex){
			System.out.println(ex);
		}
	}
	static String process(String[] lines, int H, int W){
		char[][] map = new char[H][W];
		for(int i=0;i<lines.length;i++){
			for(int j=0;j<W;j+=4){
				char code = lines[i].charAt(j/4);
				char[] tmp = toBin(code);
				for(int k=0;k<4;k++){
					map[i][j+k] = tmp[k];
				}
			}
		}
		ArrayList<int[]> out = new ArrayList<int[]>();
		int sum = 0;
		for(int i=Math.min(H,W);i>0;){
			int[] tmp = getCount(map,H,W,i);
			if(tmp == null) break;
			sum += tmp[0]*tmp[0]*tmp[1];
			i = tmp[0]-1;
			out.add(new int[]{tmp[0],tmp[1]});
		}
		if(sum != H*W){
			System.out.println("SUM ERROR: got "+sum+", req:"+(H*W));
		}else{
			//~ System.out.println("good");
		}
		//~ print(map);
		String buf = ""+out.size()+"\r\n";
		for(int i=0;i<out.size();i++){
			if(i==out.size()-1){
				buf += ""+out.get(i)[0]+" "+out.get(i)[1]+"";
			}else{
				buf += ""+out.get(i)[0]+" "+out.get(i)[1]+"\r\n";
			}
		}
		return buf;
	}
	static int[] getCount(char[][] map, int H, int W, int N){
		//~ System.out.println(N);
		int[][] max = new int[H][W];
		for(int i=H-1;i>=0;i--){
			for(int j=W-1;j>=0;j--){
				if(map[i][j]==' '){
					max[i][j] = 0;
					continue;
				}
				if(i==H-1 || j==W-1){
					max[i][j] = 1;
				}else{
					if(map[i+1][j]==' ' || map[i][j+1]==' ' || map[i+1][j+1]==' '){
						max[i][j] = 1;
					}else{
						if(map[i][j]==map[i+1][j+1] 
						&& map[i][j]!=map[i+1][j]
						&& map[i][j]!=map[i][j+1]){
							max[i][j] = 1+Math.min(max[i+1][j+1],Math.min(max[i+1][j],max[i][j+1]));
						}else{
							max[i][j] = 1;
						}
					}
				}
			}
		}
		boolean debug = false;
		//~ if(H*W==140){
			//~ debug = true;
		//~ }
		int out = 0;
		while(N>0 && out==0){
			for(int i=0;i<H;i++){
				for(int j=0;j<W;j++){
					if(max[i][j]==N){
						boolean valid = true;
						for(int y=i;y-i<N;y++){
							for(int x=j;x-j<N;x++){
								if(max[y][x] == 0){
									valid = false;
								}
							}
						}
						if(!valid) continue;
						out ++;
						if(debug){
							System.out.println(Arrays.toString(new int[]{i,j}));
						}
						for(int y=i;y-i<N;y++){
							for(int x=j;x-j<N;x++){
								max[y][x] = 0;
								map[y][x] = ' ';
							}
						}
					}
				}
			}
			if(out==0) N --;
		}
		if(debug){
			System.out.println(N);
			print(map);
		}
		if(N==0) return null;
		return new int[]{N,out};
	}
	static void print(char[][] buf){
		for(int i=0;i<buf.length;i++){
			for(int j=0;j<buf[0].length;j++){
				System.out.print(" ");
				if(buf[i][j]=='B'){System.out.print("M");}
				else if(buf[i][j]=='W'){System.out.print("O");}
				else {System.out.print(" ");}
			}
			System.out.println();
		}
		System.out.println();
	}
	static char[] toBin(char c){
		if(c>='0' && c<='9') return toCharArray(c-'0');
		return toCharArray(c-'A'+10);
	}
	static char[] toCharArray(int v){
		char[] out = new char[4];
		for(int i=0;i<4;i++){
			if((v&(1<<i))==0){
				out[3-i] = 'B';
			}else{
				out[3-i] = 'W';
			}
		}
		return out;
	}
	static int[] toIntArray(String line){
		String[] p = line.trim().split("\\s+");
		int[] out = new int[p.length];
		for(int i=0;i<out.length;i++) out[i] = Integer.valueOf(p[i]);
		return out;
	}
	
	static String toFnOut(String fn){
		if(fn.lastIndexOf('.')!=-1){
			return fn.substring(0,fn.lastIndexOf('.'))+".out";
		}else return fn + ".out";
	}
}
