import java.util.*;
import java.io.*;
public class Main{
    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("C-small-1-attempt2.in"));
        BufferedWriter bw=new BufferedWriter(new FileWriter("solve.txt"));
        int T=Integer.parseInt(br.readLine().trim());
        StringTokenizer s;
        for(int t=1;t<=T;t++){
        	s=new StringTokenizer(br.readLine().trim());
        	int N=Integer.parseInt(s.nextToken());
        	int K=Integer.parseInt(s.nextToken());
        	double[] arr=new double[N];
        	double U=Double.parseDouble(br.readLine().trim());
        	s=new StringTokenizer(br.readLine().trim());
        	for(int i=0;i<N;i++){
        		arr[i]=Double.parseDouble(s.nextToken());
        	}
        	Arrays.sort(arr);
        	double pro=0;
        	for(int i=0;i<N;i++){
        		if(i!=N-1){
        			if(U>((i+1)*(arr[i+1]-arr[i]))){
        				U-=((i+1)*(arr[i+1]-arr[i]));
        			}else{
        				pro=Math.pow((arr[i]+(U/(i+1))),i+1);
        				for(int j=i+1;j<N;j++){
        					pro*=arr[j];
        				}
        				break;
        			}
        		}else{
        			pro=Math.pow((U/N)+arr[i], N);
        		}
        	}
        	bw.write("Case #"+t+": ");
        	bw.write(String.format("%.6f\n", pro));
        }
        br.close();
        bw.close();
        return;
    }
}