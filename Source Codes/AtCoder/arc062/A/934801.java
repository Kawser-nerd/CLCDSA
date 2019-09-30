import java.util.*;
public class Main{
    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext()){
        	int n = cin.nextInt();
        	int[][] vote = readMatrix(cin,n,2);
        	System.out.println(getNum(vote,n));
        }
    }
    public static long getNum(int[][] vote, int n){
    	long[] result={vote[0][0],vote[0][1]};
    	long result1;
    	for(int i=1;i<n;i++){
    		result1 = result[1];
    		if(result[0]>vote[i][0]){
    			if(result[0]%vote[i][0]!=0) result[0] += vote[i][0]-result[0]%vote[i][0];
    		}else{result[0]=vote[i][0];}
    		result[1] = result[0]/vote[i][0]*vote[i][1];
    		if(result1>result[1]){
    			result[1] = result1;
    			if(result[1]%vote[i][1]!=0) result[1] += vote[i][1]-result[1]%vote[i][1];
    			 result[0] = result[1]/vote[i][1]*vote[i][0];
    		}
    	}
    	return result[0]+result[1];
    }
    public static int[][] readMatrix(Scanner in,int n,int m){
    	int[][] mtx = new int[n][m];
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			mtx[i][j] = in.nextInt();
    		}
    	}
    	return mtx;
    }
    
}