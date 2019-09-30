import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);

		int N=sc.nextInt();
		int M=sc.nextInt();

		Shop[] shop=new Shop[N];

		for(int i=0;i<N;i++) {
			shop[i]=new Shop();
			shop[i].price=sc.nextLong();
			shop[i].stock=sc.nextInt();
		}

		Arrays.sort(shop);

		int now_Drink=0;
		int Drink_count=0;
		long ans=0;


		for (int i=0;i<N;i++){

			now_Drink=shop[i].stock;

			if(M < Drink_count+now_Drink) {
				now_Drink=(M-Drink_count);
			}

			ans+=(now_Drink*shop[i].price);
			Drink_count+=now_Drink;

			if(Drink_count==M) break;

        }

		System.out.println(ans);

		sc.close();
	}

}


class Shop implements Comparable<Shop>{
	Long price;
	int stock;

	@Override
	public int compareTo(Shop s) {
		long x=this.price-s.price;
		if(x > 0) return 1;
		else if(x == 0) return 0;
		else return -1;
	}
}