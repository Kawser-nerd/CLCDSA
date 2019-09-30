//~ 06:35:09
import java.util.*;
import java.io.*;

public class CPark{
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
				int[] a = toIntArray(br.readLine());
				int[] b = toIntArray(br.readLine());
				String buf = process(a[0],a[1],b);
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
	static String process(int R, int K, int[] g){
		int[][] buf = new int[g.length][3];
		for(int i=0;i<g.length;i++){
			int sum = 0;
			int index = 0;
			for(int j=0;j<g.length;j++){
				index = (i+j)%g.length;
				if(sum+g[index]<=K){
					sum += g[index];
				}else{
					break;
				}
			}
			buf[i][0] = index;//next
			buf[i][1] = sum;
		}
		long out = 0;
		int cpos = 0;
		for(int i=0;i<R;i++){
			out += buf[cpos][1];
			cpos = buf[cpos][0];
		}
		return ""+out;
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
