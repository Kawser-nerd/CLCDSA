//~ 06:12:32
import java.util.*;
import java.io.*;
import java.math.*;

public class BFair{
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
				
				String buf = process(br.readLine());
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
	static String process(String line){
		String[] parts = line.split("[ ]");
		BigInteger[] values = new BigInteger[parts.length-1];
		for(int i=1;i<parts.length;i++){
			values[i-1] = new BigInteger(parts[i]);
		}
		Arrays.sort(values);
		BigInteger dev = values[1].subtract(values[0]);
		for(int i=0;i<values.length-2;i++){
			BigInteger b = values[i+2].subtract(values[i+1]);
			dev = dev.gcd(b);
		}
		BigInteger buf = values[0].mod(dev);
		if(buf.compareTo(BigInteger.valueOf(0))==0){
			return "0";
		}
		buf = dev.subtract(buf);
		return buf.toString();
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
