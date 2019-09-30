import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.next());
		
		int[] height = new int[n];
		
		
		for(int i = 0; i < n; i++) {
			height[i] = sc.nextInt();
		}
		
		int[] allzero = new int[n];
		Arrays.fill(allzero, 0);
		
		int count = 0;
		while(true) {
			
			if(Arrays.equals(height, allzero)) {
				break;
			}
			
			for(int i = 0; i < n; i++) {
				int f = height[i];
				
				if(f > 0){
					try{
						if(height[i + 1] == 0){
							count++;
						}
					}catch (Exception e){
						count++;
					}
					
					height[i]--;
				}else{
					continue;
				}
			}
		}
		System.out.println(count);
	}
}