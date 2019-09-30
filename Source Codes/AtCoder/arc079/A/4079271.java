import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Scanner stdin = new Scanner( System.in);
		int N,M;
		int a,b;
		List<Integer> alist=new ArrayList<Integer>() ;
		List<Integer> blist=new ArrayList<Integer>() ;
		N=stdin.nextInt();
		M=stdin.nextInt();
		for(int i=1;i<=M;i++){
			a=stdin.nextInt();
			b=stdin.nextInt();
			if(a==1)alist.add(b);
			if(b==N)blist.add(a);
		}
		Collections.sort(alist);
		Collections.sort(blist);
		Stack<Integer> astack=new Stack<Integer>();
		Stack<Integer> bstack=new Stack<Integer>();
		for(int i=0;i<alist.size();i++){
			astack.push(alist.get(i));
		}
		for(int i=0;i<blist.size();i++){
			bstack.push(blist.get(i));
		}
		
		if(astack.empty()||bstack.empty()){
			System.out.print("IMPOSSIBLE");
			System.exit(0);
		}
		a=astack.pop();
		b=bstack.pop();
		do{
			if(a<b){
				if(bstack.empty())break;
				b=bstack.pop();
			}
			if(a>b){
				if(astack.empty())break;
				a=astack.pop();
			}
			if(a==b){
				System.out.print("POSSIBLE");
				System.exit(0);
			}
		}while(true);
				
		System.out.print("IMPOSSIBLE");
	}
}