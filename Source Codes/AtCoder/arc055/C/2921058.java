import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Zalgo{
	String s;
	int[] presize; // S?S[i:]?????????

	Zalgo(String s){
		this.s=s;
		presize = new int[s.length()];
		presize[0] = s.length();
		int index=1, size=0;
		while(index<s.length()){
			while(index+size<s.length() && s.charAt(size)==s.charAt(index+size))++size;
			presize[index]=size;
			if(size==0){
				++index;
				continue;
			}
			int k=1;
			while(k+index < s.length() && k+presize[k]<size){
				presize[index+k] = presize[k]; ++k;
			}
			index+=k;size-=k;
		}
	}
}

class Main{ 

	static void solve(){
		String s = ns();
		String rs = new StringBuilder(s).reverse().toString();
		Zalgo sz = new Zalgo(s);
		Zalgo rsz= new Zalgo(rs);
		long ans =0;
		for(int i=s.length()-2;i>s.length()/2;--i){
			int x = rsz.presize[s.length()-i];
			int y = sz.presize[i];
			int add = Math.min(Math.min(x, y), (x+y-(s.length()-1-i)));
			add = Math.min(s.length()-1-i, add);
			ans +=Math.max(0, add);
		}
		out.println(ans);
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