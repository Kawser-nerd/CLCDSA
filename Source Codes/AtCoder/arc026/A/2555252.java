import java.util.Scanner;
class Main{
	static int min(int a,int b){
    	if(a>b)return b;
        else return a;
	}
  	static void solve(){
    	int n,sc,di;
    	Scanner cin = new Scanner(System.in);
    	n=cin.nextInt();
    	sc=cin.nextInt();
    	di=cin.nextInt();
    	System.out.println((min(n,5)*di)+(n-min(n,5))*sc);
  	}
  
  	public static void main(String args[]){
    	solve();
  	}
}