import java.util.*;
import java.io.*;
public class Main {
	public static long[] solve(long N,long K){
		if(K==1){
			long[] arr=new long[2];
			arr[0]=N/2;
			arr[1]=(N-1)/2;
			return arr;
		}
		if(K%2==0){
			return solve(N/2,K/2);
		}
		return solve((N-1)/2,K/2);
		
	}
    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("C-large.in"));
        BufferedWriter bw=new BufferedWriter(new FileWriter("solve.txt"));
        int T=Integer.parseInt(br.readLine().trim());
        StringTokenizer s;
        for(int i=1;i<=T;i++){
        	bw.write("Case #"+i+": ");
        	s=new StringTokenizer(br.readLine().trim());
        	long N=Long.parseLong(s.nextToken());
        	long K=Long.parseLong(s.nextToken());
        	long[] arr=solve(N,K);
        	bw.write(arr[0]+" "+arr[1]+"\n");
        }
        br.close();
        bw.close();
        return;
    }
}
