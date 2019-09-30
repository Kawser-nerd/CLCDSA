import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("A-large.in"));
        BufferedWriter bw=new BufferedWriter(new FileWriter("solve.txt"));
        int T=Integer.parseInt(br.readLine().trim());
        StringTokenizer s;
        for(int i=1;i<=T;i++){
        	s=new StringTokenizer(br.readLine().trim());
        	String S=s.nextToken();
        	int K=Integer.parseInt(s.nextToken());
        	int len=S.length();
        	int num=0;
        	boolean ok=true;
        	int[] data=new int[len];
        	for(int j=0;j<=len-K;j++){
        		if((S.charAt(j)=='-'&&data[j]%2==0)||(S.charAt(j)=='+'&&data[j]%2==1)){
        			num++;
        			for(int k=1;k<K;k++){
        				data[j+k]++;
        			}
        		}
        	}
        	for(int j=len-K+1;j<len;j++){
        		if((S.charAt(j)=='-'&&data[j]%2==0)||(S.charAt(j)=='+'&&data[j]%2==1)){
        			ok=false;
        			break;
        		}
        	}
        	bw.write("Case #"+i+": ");
        	if(ok){
        		bw.write(num+"\n");
        	}else{
        		bw.write("IMPOSSIBLE\n");
        	}
        }
        br.close();
        bw.close();
        return;
    }
}
