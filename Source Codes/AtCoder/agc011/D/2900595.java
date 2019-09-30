import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.lang.StringBuilder;
import java.util.Arrays;

class Main{ 

	static void solve(){ 
		int n = ni(), k=ni();
		char[] sarr =ns().toCharArray();
		StringBuilder BA = new StringBuilder();
		for(int i=0;i<=n/2;++i)BA.append("BA");
		StringBuilder  ans = new StringBuilder();
		boolean rev = false;
		int index=0;
		char[] revc = new char[256];
		revc['A']='B';
		revc['B']='A';
		if(n==1){
			if(k%2==0)out.println(sarr[0]);
			else out.println(revc[sarr[0]]);
			return;
		}
		for(;index<n;++index){
			if(k==0)break;
			if((!rev&&sarr[index]=='A') || (rev&&sarr[index]=='B')){
				--k;sarr[index]=revc[sarr[index]];
			}
			if(k==0)break;
			rev=!rev;
			--k;
		}

		for(;index<n;++index){
			if(rev)ans.append(revc[sarr[index]]);
			else ans.append(sarr[index]);
		}
		ans.append(BA.substring(BA.length()-(n-ans.length())));
		if(index==n && k%2==1)ans.setCharAt(0, 'B');
		out.println(ans.toString());
	}
 
 
 
 
	public static void main(String[] args){ 
		 solve(); 
		 out.flush(); 
	 } 
	 private static InputStream in = System.in; 
	 private static PrintWriter out = new PrintWriter(System.out); 
 
	 private static final byte[] buffer = new byte[1<<15]; 
	 private static int ptr = 0; 
	 private static int buflen = 0; 
	 private static boolean hasNextByte(){ 
		 if(ptr<buflen)return true; 
		 ptr = 0; 
		 try{ 
			 buflen = in.read(buffer); 
		 } catch (IOException e){ 
			 e.printStackTrace(); 
		 } 
		 return buflen>0; 
	 } 
	 private static int readByte(){ if(hasNextByte()) return buffer[ptr++]; else return -1;} 
	 private static boolean isSpaceChar(int c){ return !(33<=c && c<=126);} 
	 private static int skip(){int res; while((res=readByte())!=-1 && isSpaceChar(res)); return res;} 
 
	 private static double nd(){ return Double.parseDouble(ns()); } 
	 private static char nc(){ return (char)skip(); } 
	 private static String ns(){ 
		 StringBuilder sb = new StringBuilder(); 
		 for(int b=skip();!isSpaceChar(b);b=readByte())sb.append((char)b); 
		 return sb.toString(); 
	 } 
	 private static int[] nia(int n){ 
		 int[] res = new int[n]; 
		 for(int i=0;i<n;++i)res[i]=ni(); 
		 return res; 
	 } 
	 private static long[] nla(int n){ 
		 long[] res = new long[n]; 
		 for(int i=0;i<n;++i)res[i]=nl(); 
		 return res; 
	 } 
	 private static int ni(){ 
		 int res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	 } 
	 private static long nl(){ 
		 long res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	} 
}