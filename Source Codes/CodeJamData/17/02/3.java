import java.util.*;
import java.io.*;
public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("B-large.in"));
        BufferedWriter bw=new BufferedWriter(new FileWriter("solve.txt"));
        int T=Integer.parseInt(br.readLine().trim());
        StringTokenizer s;
        for(int i=1;i<=T;i++){
        	bw.write("Case #"+i+": ");
        	s=new StringTokenizer(br.readLine().trim());
        	String S=s.nextToken();
        	int len=S.length();
        	int[] digit=new int[len];
        	for(int j=0;j<len;j++){
        		digit[j]=S.charAt(j)-'0';
        	}
        	for(int j=len-1;j>0;j--){
        		if(digit[j]<digit[j-1]){
        			digit[j-1]--;
        			for(int k=j;k<len;k++){
        				digit[k]=9;
        			}
        		}
        	}
        	for(int j=0;j<len;j++){
        		if(!(j==0&&digit[j]==0)){
        			bw.write(digit[j]+"");
        		}
        	}
        	bw.write("\n");
        }
        br.close();
        bw.close();
        return;
    }
}
