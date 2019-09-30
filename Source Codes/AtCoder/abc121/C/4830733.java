import java.util.Arrays;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long m = sc.nextInt();
		Store[] stores = new Store[n];
		for(int i = 0;i < n;i ++) {
			int price = sc.nextInt(), max = sc.nextInt();
			stores[i] = new Store(price,max);
		}
		Arrays.sort(stores);
		long drinksum = 0, pricesum = 0,diff = 0;
		for(int i = 0;i < n;i ++) {
			Store s = stores[i];
			long max = Long.valueOf(s.max);
			long price = Long.valueOf(s.price);
			drinksum += max;
			if(drinksum > m) {
				diff = drinksum - m;
				pricesum += price * (max - diff);
				break;
			}else if (drinksum == m) {
				pricesum += price * max;
				break;
			}
			pricesum += price * max;
		}
		System.out.println(pricesum);
	}
}

class Store implements Comparable<Store>{
	int price;
	int max;
	
	public Store(int price,int max){
		this.price = price;
		this.max = max;
	}

	@Override
	public int compareTo(Store s) {
		return this.price - s.price;
	}
}