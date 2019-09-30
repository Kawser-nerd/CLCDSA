import java.util.Scanner;

public class Main {
static int ans,N;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N=sc.nextInt();
		dfs(0,"");
        }
    	public static void dfs(int n,String s) {
    		if(n==N) {
    			System.out.println(s);
    			return;
    		}
    			dfs(n+1,s+"a");
    			dfs(n+1,s+"b");
    			dfs(n+1,s+"c");
    	}
    }