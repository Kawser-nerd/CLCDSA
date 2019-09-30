import java.util.*;
import java.io.*;
public class Main{
	public static int[] visited;
	public static int[] A;
	public static int[] B;
	public static ArrayList<Integer>[] next=new ArrayList[201];	
	public static boolean dfs(int a){
		visited[a]=1;
		int len=next[a].size();
		for(int i=0;i<len;i++){
			int b=next[a].get(i);
			if(B[b]==0||(visited[B[b]]==0&&dfs(B[b]))){
				A[a]=b;
				B[b]=a;
				return true;
			}
		}
		return false;
	}
    public static void main(String[] args) throws Exception{
        BufferedReader br=new BufferedReader(new FileReader("D-large.in"));
        BufferedWriter bw=new BufferedWriter(new FileWriter("solve.txt"));
        int T=Integer.parseInt(br.readLine().trim());
        StringTokenizer s;
        for(int i=1;i<=T;i++){
        	StringBuffer sb=new StringBuffer();
        	s=new StringTokenizer(br.readLine().trim());
        	int point=0;
        	int num=0;
        	int N=Integer.parseInt(s.nextToken());
        	int M=Integer.parseInt(s.nextToken());
        	int[][] grid=new int[N+1][N+1];
        	int[][] Bishop=new int[2][2*N+1];
        	int[][] gridx=new int[2][N+1];
        	A=new int[2*N+1];
        	B=new int[2*N+1];
        	for(int j=0;j<M;j++){
        		s=new StringTokenizer(br.readLine().trim());
        		char ch=s.nextToken().charAt(0);
        		int R=Integer.parseInt(s.nextToken());
        		int C=Integer.parseInt(s.nextToken());
        		if(ch!='x'){
        			Bishop[0][R+C]=1;
        			Bishop[1][R-C+N+1]=1;
        			point++;
        		}
        		if(ch!='+'){
        			gridx[0][R]=1;
        			gridx[1][C]=1;
        			point++;
        		}
        		grid[R][C]=1;        		
        	}
        	for(int j=2;j<=2*N;j++){
        		if(Bishop[0][j]==0){
        			next[j]=new ArrayList<Integer>();
        			if(j<=N+1){
        				for(int k=N+3-j;k<N+j;k+=2){
        					if(Bishop[1][k]==0){
        						next[j].add(k);
        					}
        				}
        			}else{
        				for(int k=j-N+1;k<3*N+2-j;k+=2){
        					if(Bishop[1][k]==0){
        						next[j].add(k);
        					}
        				}
        			}
        		}
        	}        	
        	for(int j=2;j<=2*N;j++){
        		if(Bishop[0][j]==0){
        			if(A[j]==0){
        				visited=new int[2*N+1];
        				dfs(j);
        			}
        		}
        	}
        	for(int j=2;j<=2*N;j++){        		
        		if(Bishop[0][j]==0&&A[j]!=0){        			
        			int R=(j+A[j]-(N+1))/2;
        			int C=j-R;
        			if(gridx[0][R]==0&&gridx[1][C]==0){
        				sb.append("o "+R+" "+C+"\n");
            			point+=2;
            			num++;
            			gridx[0][R]=1;
            			gridx[1][C]=1;
        			}else if(grid[R][C]==1){
        				sb.append("o "+R+" "+C+"\n");
            			point++;
            			num++;
        			}else{
        				sb.append("+ "+R+" "+C+"\n");
            			point++;
            			num++;
        			}
        		}
        	}
        	for(int j=0,k=0;;){
        		for(;;){
        			j++;
        			if(j==N+1||gridx[0][j]==0){
        				break;
        			}        			
        		}
        		if(j==N+1){
        			break;
        		}
        		for(;;){
        			k++;
        			if(k==N+1||gridx[1][k]==0){
        				break;
        			}
        			
        		}
        		if(k==N+1){
        			break;
        		}
        		if(grid[j][k]==1){
        			sb.append("o "+j+" "+k+"\n");
        			point++;
        			num++;
        		}else{
        			sb.append("x "+j+" "+k+"\n");
        			point++;
        			num++;
        		}
        	}
        	bw.write("Case #"+i+": "+point+" "+num+"\n");
        	bw.write(sb.toString());        	
        }
        br.close();
        bw.close();
        return;
    }
}