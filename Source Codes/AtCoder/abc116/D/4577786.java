import java.util.Scanner;
import java.util.Arrays;
import java.util.Comparator;
import java.util.ArrayList;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] val=new int[n+1];
		Sushi[] box=new Sushi[n];
		ArrayList<Long> list=new ArrayList<Long>();
		for(int i = 0; i<n; i++){
			int t = sc.nextInt();
			long d = sc.nextLong();
			box[i]=new Sushi(t,d);
		}
		Arrays.sort(box,Comparator.comparing(Sushi::getD).reversed());
		long sum=0;
		long vali=0;
		for(int i = 0; i<k; i++){
			sum+=box[i].d;
			if(val[box[i].t]==0){
				vali++;
			}else{
				list.add(box[i].d);
			}
			val[box[i].t]++;
		}
		long ans=vali*vali+sum;
		if(list.size()==0){
			System.out.println(ans);
			return;
		}
		int min=list.size()-1;
		for(int i=k; i<n; i++){
			if(val[box[i].t]==0){
				vali++;
				val[box[i].t]++;
				sum+=box[i].d-list.get(min);
				min--;
				ans=Math.max(ans,vali*vali+sum);
				if(min==-1){
					break;
				}
			}
		}
		System.out.println(ans);
	}
	static class Sushi{
		int t;
		long d;
		public Sushi(int t, long d){
			this.t=t;
			this.d=d;
		}
		public long getD(){
			return this.d;
		}
	}
}