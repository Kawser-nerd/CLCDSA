import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		new Main().solve();
	}
	void solve(){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		long[] a=new long[n];
		long[] b=new long[n];
		ArrayList<Pair> list_plus=new ArrayList<Pair>();
		ArrayList<Pair> list_minus=new ArrayList<Pair>();
		ArrayList<Pair> list_zero=new ArrayList<Pair>();
		for(int i=0;i<n;i++){
			//?????????????????????
			a[i]=sc.nextLong();
			b[i]=sc.nextLong();
			if(a[i]-b[i]<0)list_minus.add(new Pair(a[i],b[i]));
			if(a[i]-b[i]==0)list_zero.add(new Pair(a[i],b[i]));
			if(a[i]-b[i]>0)list_plus.add(new Pair(a[i],b[i]));
		}
		list_minus.sort(new Comparator<Pair>(){
			@Override
			public int compare(Pair o1, Pair o2) {
				int judge= Long.compare(o1.a, o2.a);
				if(judge!=0)return judge;
				else{
					return Long.compare(-o1.b, -o2.b);
				}
			}
		});
		list_plus.sort(new Comparator<Pair>(){
			@Override
			public int compare(Pair o1, Pair o2) {
				int judge= -Long.compare(o1.b, o2.b);
				if(judge!=0)return judge;
				else{
					return Long.compare(o1.a, o2.a);
				}
			}
		});
		long max=0;
		long now=0;
		for(int i=0;i<list_minus.size();i++){
			max=Math.max(max, now+list_minus.get(i).a);
			now+=list_minus.get(i).a-list_minus.get(i).b;
		}
		for(int i=0;i<list_zero.size();i++){
			max=Math.max(max, now+list_zero.get(i).a);
			now+=list_zero.get(i).a-list_zero.get(i).b;
		}
		for(int i=0;i<list_plus.size();i++){
			max=Math.max(max, now+list_plus.get(i).a);
			now+=list_plus.get(i).a-list_plus.get(i).b;
		}
		System.out.println(max);

		/**
		 * b[i]>0?????????,
		 * a[i]???????????????
		 * 
		 * b[i]<0??????????
		 * a[i]???????????????
		 * 
		 * b[i]>0&&b[j]<0????j??????????????
		 * 
		 */

	}
	class Pair{
		long a;
		long b;
		Pair(long a,long b){
			this.a=a;
			this.b=b;
		}
	}
}