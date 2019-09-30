import java.io.*;
import java.util.*;

public class C {
	
	public static BufferedReader in;
	public static StringTokenizer st;
	
	public static long money, fee;
	
	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			
			money = readLong();
			fee = readLong();
			int num = readInt();
			
			Meal[] arr = new Meal[num];
			for (int i=0; i<num; i++)
				arr[i] = new Meal(readLong(), readLong());
			
			Arrays.sort(arr);
			long numDays = 0, cost = fee;
			ArrayList<Meal> store = new ArrayList<Meal>();
			for (int i=0; i<arr.length; i++){
				if(arr[i].stale<numDays) continue;
				if(arr[i].price>arr[0].price+fee) break;
				cost += arr[i].price*(arr[i].stale-numDays+1);
				store.add(new Meal(arr[i].price, arr[i].stale-numDays+1));
				numDays = arr[i].stale+1;
			}
			
			long lower = money/cost;
			long upper = money/fee;
			
			while(upper-lower>2){
				long mid1 = lower+(upper-lower)/3;
				long mid2 = upper-(upper-lower)/3;
				long first = compute(mid1, store);
				long second = compute(mid2, store);
				if(first<second)
					lower=mid1;
				else
					upper=mid2;
			}
			long ans = compute(upper, store);
			for (long i = lower; i<upper; i++){
				long poss = compute(i, store);
				if (poss>ans) ans = poss;
			}
			out.println(ans);
			
			/*if(money%cost<fee){
				out.println(numDays*mult);
				continue;
			}
			
			mult++;
			money-=mult*fee;
			int ans = 0;
			for(int i=0; i<store.size(); i++){
				long afford = money/store.get(i).price;
				long days = store.get(i).stale*mult;
				ans+=min(afford, days);
				money-=store.get(i).price*min(afford, days);
				if(afford<days) break;
			}
			out.println(ans);
			
			/*long ans = numDays*mult;
			money = money%cost;
			
			numDays = 0; cost = fee;
			int i=0;
			for (;i<arr.length; i++){
				if(arr[i].stale<numDays) continue;
				if(arr[i].price+cost>money) break;
				long afford = (money-cost)/arr[i].price;
				long days = min(afford, arr[i].stale-numDays+1);
				cost += arr[i].price*(days);
				numDays += days;
				if (numDays<arr[i].stale+1) break;
			}
			ans+=numDays;
			money -= cost;
			if (money<0){
				out.println(ans);
				continue;
			}
			System.out.print(money+" ");
			int index = store.size()-1;
			long left = mult*store.get(index).stale;
			for (; i<arr.length && index>0; i++){
				long days = arr[i].stale-numDays+1;
				if(arr[i].price>=store.get(index).price) break;
				money-=(arr[i].price-store.get(index).price)*min(left, days);
				numDays+=min(left, days);
				left-=days;
				if(left<=0){
					index--; left = mult*store.get(index).stale; i--;
				}
			}
			System.out.println(arr[i].price+" "+store.get(index).price+" "+money);
			
			for (; index<store.size(); index++, left=mult*store.get(index).stale){
				//
			}
			
			out.println(ans);*/
		}
		
		out.close();
		in.close();
	}
	
	public static long compute(long mult, ArrayList<Meal> store){
		long mon = money-mult*fee;
		long ans = 0;
		for(int i=0; i<store.size(); i++){
			long afford = mon/store.get(i).price;
			long days = store.get(i).stale*mult;
			ans+=min(afford, days);
			mon-=store.get(i).price*min(afford, days);
			if(afford<days) break;
		}
		return ans;
	}

	public static long min(long a, long b){
		return a<b?a:b;
	}
	
	public static String readLine() throws IOException{
		return in.readLine();
	}
	
	public static String readToken() throws IOException{
		while(st==null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return st.nextToken();
	}
	
	public static int readInt() throws IOException{
		return Integer.parseInt(readToken());
	}
	
	public static long readLong() throws IOException{
		return Long.parseLong(readToken());
	}
}

class Meal implements Comparable<Meal>{
	long price;
	long stale;
	
	public Meal(long p, long s){
		price = p;
		stale = s;
	}
	
	public int compareTo(Meal other){
		if (price==other.price)
			return other.stale-stale<0?-1:1;
		return price-other.price<0?-1:1;
	}
}