import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("A-large.in"));
        BufferedWriter bw=new BufferedWriter(new FileWriter("solve.txt"));
        int T=Integer.parseInt(br.readLine().trim());
        StringTokenizer s;        
        for(int t=1;t<=T;t++){        	
        	s=new StringTokenizer(br.readLine().trim());
        	int N=Integer.parseInt(s.nextToken());
        	int K=Integer.parseInt(s.nextToken());
        	long[][] arr=new long[N][3];
        	for(int i=0;i<N;i++){
        		s=new StringTokenizer(br.readLine().trim());
        		arr[i][0]=Integer.parseInt(s.nextToken());
        		arr[i][1]=Integer.parseInt(s.nextToken());
        		arr[i][2]=arr[i][0]*arr[i][1]*2;
        		arr[i][0]=arr[i][0]*arr[i][0];
        	}
        	Arrays.sort(arr,new Comparator<long[]>(){
        		public int compare(long[] a,long[] b){
        			if(a[2]==b[2]){
        				return Long.compare(a[0],b[0]);
        			}else{
        				return Long.compare(a[2], b[2]);
        			}
        		}
        	});
        	long sum=0;
        	long max=0;
        	long val=0;
        	for(int i=1;i<K;i++){
        		sum+=arr[N-i][2];
        		max=Math.max(arr[N-i][0],max);
        	}
        	for(int i=K;i<=N;i++){
        		val=Math.max(val,sum+Math.max(max, arr[N-i][0])+arr[N-i][2]);
        	}
        	bw.write("Case #"+t+": ");
        	bw.write(String.format("%.9f\n", Math.PI*val));
        }
        br.close();
        bw.close();
        return;
    }
}