//~ 16:00:52
import java.util.*;
import java.io.*;

public class ARope{
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
				int n = Integer.valueOf(br.readLine());
				int maxHeight = 10001;
				int[] h = new int[maxHeight];
				for(int i=0;i<n;i++){
					int[] b = toIntArray(br.readLine());
					h[b[0]] = b[1];
				}
				String buf = process(h);
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
	static String process(int[] h){
		int out = 0;
		for(int i=0;i<h.length;i++){
			if(h[i]==0) continue;
			for(int j=i+1;j<h.length;j++){
				if(h[j]>0 && h[j]<h[i]) out++;
			}
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
