import java.io.*;
import java.util.StringTokenizer;
import java.util.HashSet;
import java.util.Arrays;
public class A{
	private static String[] dictionary;
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		StringTokenizer getInfo = new StringTokenizer(in.readLine());
		int L = Integer.parseInt(getInfo.nextToken());
		int D = Integer.parseInt(getInfo.nextToken());
		int N = Integer.parseInt(getInfo.nextToken());
		dictionary = new String[D];
		BufferedWriter out = new BufferedWriter(new FileWriter("A-large.out"));
		for(int i = 0; i < D; i++){
			String s = in.readLine();
			dictionary[i]=s;
			System.out.println("Added "+s);
		}
		Arrays.sort(dictionary);
		for(int i = 1; i <= N; i++){
			System.out.println("Working on "+i);
			out.write("Case #"+i+": "+possible(in.readLine(),0,"",0,dictionary.length)+"\n");
		}
		out.close();
	}
	private static int possible(String s, int startAt, String soFar, int startD, int endD){	
		if(startAt==s.length()){
			for(int i = startD; i<endD; i++){
				if(dictionary[i].equals(soFar)) return 1;
			}
			return 0;
		}
		int x = -1-Arrays.binarySearch(dictionary,startD,endD,soFar);
		if(x>=0 && x<dictionary.length && dictionary[x].startsWith(soFar)){
			startD = x;
			for(endD = startD+1; endD<dictionary.length && dictionary[endD].startsWith(soFar); endD++);
		}
		else{
			return 0;
		}
		if(s.charAt(startAt)=='('){
			int ans = 0;
			int stop = s.indexOf(")",startAt);
			for(int i = startAt+1; i<stop; i++){
				ans+=possible(s,stop+1,soFar+s.charAt(i),startD,endD);
			}
			return ans;
		}
		return possible(s,startAt+1,soFar+s.charAt(startAt),startD,endD);
	}
}