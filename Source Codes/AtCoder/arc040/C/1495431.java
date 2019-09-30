import java.util.*;

public class Main{
    
    static char[][] g;
    static int n;
    
    static void p(int r,int c){
       for(int i=0;i<=c;i++) g[r][i]='o';
       if(r+1<n) for(int i=c;i<n;i++) g[r+1][i]='o'; 
    }

    public static void main(String[] args){
           
      Scanner sc = new Scanner(System.in);
        

			n=sc.nextInt();
			g=new char[n][n];
			for(int i=0;i<n;i++){
				String str=sc.next();
				for(int j=0;j<n;j++) g[i][j]=str.charAt(j);
			}
			int ans=0;
			for(int i=0;i<n;i++){
				for(int j=n-1;j>=0;j--){
					if(g[i][j]=='.'){
						ans++;
						p(i,j);
					}
				}
			}
			System.out.println(ans);

                  
    }        
}