import java.io.*;
import java.util.Arrays;
public class C{
	private static int[][] cache;
	private static final char[] toFind = new char[] {'w','e','l','c','o','m','e',' ','t','o',' ','c','o','d','e',' ','j','a','m'};
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C-large.out"));
		int N = Integer.parseInt(in.readLine());
		for(int i = 1; i <= N; i++){
			System.out.println("Started working on #"+i);
			out.write("Case #"+i+": ");
			char[] toSearch = in.readLine().toCharArray();
			cache = new int[toSearch.length][toFind.length];
			for(int x = 0; x < cache.length; x++) Arrays.fill(cache[x],-1);
			int ans = go(toSearch,0,0);
			if(ans<10)out.write("000"+ans+"\n");
			else if(ans<100)out.write("00"+ans+"\n");
			else if(ans<1000)out.write("0"+ans+"\n");
			else out.write(ans+"\n");
		}		
		out.close();
	}
	private static int go(char[] toSearch, int startSearch, int lookFor){
		if(lookFor==toFind.length) return 1;
		if(startSearch==toSearch.length) return 0;
		if(cache[startSearch][lookFor]!=-1) return cache[startSearch][lookFor];
		int ans=0;
		for(int i = startSearch; i < toSearch.length; i++){
			if(toSearch[i]==toFind[lookFor]) ans=(ans+go(toSearch,i+1,lookFor+1))%10000;
		}
		cache[startSearch][lookFor]=ans;
		return ans;
	}
}