import java.util.*;
import java.io.*;

class Main{
	public static void main(String[] args){
		new Main().run();
	}

	void run(){
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int A=sc.nextInt();
		int B=sc.nextInt();
		if(!(A+B-1<=N&&N<=(long)A*B)){
			System.out.println(-1);
			return;
		}
		PrintWriter pw=new PrintWriter(System.out);
		int cur=N;
		int cnt=0;
		for(int i=0;i<B;++i){
			int tmp=Math.min(cur-(B-1-i),A);
			for(int j=0;j<tmp;++j){
				pw.print(cur-(tmp-1)+j);
				++cnt;
				if(cnt==N){
				    pw.println("\n");
				}else{
				    pw.print(" ");
				}
			}
			cur-=tmp;
		}
		pw.close();	
	}
}