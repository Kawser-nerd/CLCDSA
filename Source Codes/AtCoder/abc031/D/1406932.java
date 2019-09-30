import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().solve();
	}
	
	int n,k;
	int[]v;
	String[]w;
	int[]table;
	String[]ans;
	
	void solve(){
		Scanner sc=new Scanner(System.in);
		k=sc.nextInt();
		n=sc.nextInt();
		v=new int[n];
		w=new String[n];
		ans=new String[k+1];
		
		for(int i=0;i<n;i++){
			v[i]=sc.nextInt();
			w[i]=sc.next();
		}
		
		table=new int[k+1]; //???????1~3????
		for(int i=0;i<Math.pow(3, k);i++){
			int ni=i;
			for(int j=0;j<k;j++){
				int p=ni%3+1;
				ni/=3;
				table[j+1]=p;
			}
			
			if(check()){
				
				for(int p=0;p<n;p++){
					int count=0;
					int vp=v[p];
					
					while(vp>0){
						count+=table[vp%10];
						String wi=w[p];
						int begin=wi.length()-count;
						int end=begin+table[vp%10];
						ans[vp%10]=wi.substring(begin,end);
						vp/=10;
					}
				}
				
				for(int q=1;q<=k;q++){
					System.out.println(ans[q]);
				}
				
				return;
			}
		}
		
	}
	boolean check(){
		for(int i=0;i<n;i++){
			int count=0;
			int vi=v[i];
			while(vi>0){
				count+=table[vi%10];
				vi/=10;
				
			}
			if(count!=w[i].length())return false;
		}
		return true;
	}
}