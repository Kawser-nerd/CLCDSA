import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		int numTown = input.nextInt();
		input.nextInt();
		int[] val = new int[numTown];
		for (int i = 0; i < numTown; i++) {
			val[i] = input.nextInt();
		}
		
		int maxdiff = 0;
		int count = 0;
		
		
		int[] maxright = new int[numTown];
		int[] minleft = new int[numTown];
		maxright[numTown-1] = val[numTown-1];
		minleft[0] = val[0];
		
		for(int i = 1; i < numTown; i++){
			minleft[i] = Math.min(minleft[i-1], val[i]);
		}

		for(int i = numTown-2; i >= 0; i--){
			maxright[i] = Math.max(maxright[i+1], val[i]);
		}
		
		for (int i = 0; i < numTown; i++) {
		//	System.out.println(i +" "+ minleft[i] +" "+ maxright[i]);
				if (maxright[i] - minleft[i] > maxdiff) {
					int mr = maxright[i];
					int ml = minleft[i];
					maxdiff = maxright[i] - minleft[i];
					count = 1;
					while (i < numTown && maxright[i] == mr && minleft[i] == ml) {
						i++;
					}
				} else if (maxright[i] - minleft[i] == maxdiff) {
					count++;
					int mr = maxright[i];
					int ml = minleft[i];
					while (i < numTown && maxright[i] == mr && minleft[i] == ml) {
						i++;
					}
				}
		}
		System.out.println(count);
	}
}