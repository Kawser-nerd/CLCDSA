import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 
import java.util.*;

class Main{ 

	static void solve(){
		int n = ni();
		long[] s = nla(n);
		boolean[] isPrime = new boolean[100001];
		Arrays.fill(isPrime, true);
		for(int i=2;i<=100000;++i){
			if(!isPrime[i])continue;
			for(int j=i*2;j<=100000;j+=i)isPrime[j]=false;
		}
		List<Integer> primes = new ArrayList<>();
		for(int i=2;i<=100000;++i)if(isPrime[i])primes.add(i);
		Set<Long> under1e5 = new HashSet<>();
		for(int p: primes)under1e5.add((long)p);
		under1e5.add(1L);
		List<Long> cubep = new ArrayList<>();
		for(int p : primes){
			if((long)p*p*p>(long)1e10)break;
			cubep.add((long)p);
		}
		Map<Long, Long> sqrMap = new HashMap<>();
		for(long i=2;i*i<=10000000000L;++i)sqrMap.put(i*i, i);

		Map<Long, Long> reve = new HashMap<>();
		Map<Long , Integer> cnt = new HashMap<>();
		int ans = 0;
		boolean zero=true;
		for(int i=0;i<n;++i){
			long normal = s[i];
			long rev = 1;
			for(int k=0;k<cubep.size();++k){
				long p= cubep.get(k);
				while(s[i]%(p*p*p)==0){
					s[i]/=(p*p*p);
					normal/=(p*p*p);
				}
				if(s[i]%p==0){
					if(s[i]%(p*p)==0)rev*=p;
					else rev*=p*p;
				}
				while(s[i]%p==0)s[i]/=p;
			}
			if(sqrMap.containsKey(s[i]))rev*=sqrMap.get(s[i]);
			else if(rev*s[i]*s[i] >10000000000L || rev*s[i]*s[i]<0){
				++ans;continue;
			}else rev*=s[i]*s[i];
			if(rev==1){
				if(zero)++ans;
				zero=false;continue;
			}
			reve.put(normal, rev);
			cnt.put(normal, cnt.getOrDefault(normal, 0)+1);
		}

		int ans2 = 0;
		Set<Long> used = new HashSet<>();
		for(Map.Entry<Long , Integer> entry: cnt.entrySet()){
			if(used.contains(entry.getKey()))continue;
			ans2 += Math.max(entry.getValue(), cnt.getOrDefault(reve.get(entry.getKey()), 0));
			used.add(reve.get(entry.getKey()));
		}
//		out.println(ans+" "+ans2);
		out.println(ans+ans2);
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