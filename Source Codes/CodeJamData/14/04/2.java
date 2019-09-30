import java.util.*;
public class D {
	public static void main(String[]args) {
		Scanner in = new Scanner(System.in);
			
		int inputs = in.nextInt();
		for(int caseNum = 1; caseNum <= inputs; caseNum++) {
			int blocks = in.nextInt();
			double[] naomi = new double[blocks];
			double[] ken = new double[blocks];
			for(int i = 0 ; i < blocks; i++) {
				naomi[i] = in.nextDouble();
			}
			for(int i  =0;i < blocks; i++) {
				ken[i] = in.nextDouble();
			}
			
			Arrays.sort(ken);
			Arrays.sort(naomi);
			int normal = 0;
			int i = 0;
			int j = 0;
			while(i < blocks && j < blocks) {
				if(naomi[i] < ken[j]) {
					i++;
					j++;
					normal++;
				} else {
					j++;
				}
			}
			normal = blocks - normal;
			
			
			int cheat = 0;
			i=0;j=0;
			
			while(i < blocks && j < blocks) {
				if(naomi[i] > ken[j]) {
					i++;
					j++;
					cheat++;
				} else {
					i++;
				}
			}
			
			System.out.printf("Case #%d: %d %d\n", caseNum, cheat, normal);
		}
	}
}
