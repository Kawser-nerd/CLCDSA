import java.util.*;

public class cjB {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cas = sc.nextInt();
		for(int cass = 1; cass <= cas; cass++) {
			System.out.print("Case #" + cass + ": ");
			int seats = sc.nextInt();
			int customers = sc.nextInt();
			int tickets = sc.nextInt();
			int[] perCust = new int[customers];
			int[] perSeat = new int[seats];
			int maxPerCust = 0;
			for(int ttt = 0; ttt < tickets; ttt++) {
				int ssss = sc.nextInt() - 1;
				int cccc = sc.nextInt() - 1;
				perCust[cccc]++;
				perSeat[ssss]++;
				if(perCust[cccc] > maxPerCust) {
					maxPerCust = perCust[cccc];
				}
			}
			int tt = tickets;
			int minCoast = 0;
			while(tt > 0) {
				minCoast++;
				tt -= seats;
			}
			if(minCoast < maxPerCust) minCoast = maxPerCust;
			int tot = 0;
			for(int qw = 0; qw < seats; qw++) {
				tot += perSeat[qw];
				while((minCoast * (qw + 1) < tot)) {
					minCoast++;
				}
			}
			int promo = 0;
			for(int qq = 0; qq < seats; qq++) {
				if(perSeat[qq] > minCoast) {
					promo += (perSeat[qq] - minCoast);
				}
			}
			System.out.println(minCoast + " " + promo);
		}
	}
}