import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n=sc.nextInt();
		boolean dir[]=new boolean[n];
		String s=sc.next();
		for(int i=0;i<n;i++){
			if(s.charAt(i)=='E') dir[i]=true;
		}
		
		int cost=0;
		for(int i=1;i<n;i++) if(dir[i])cost++;

		int min_cost=cost;
		for(int reader=1;reader<n;reader++){
			if(!dir[reader-1])cost++;
			if(dir[reader])cost--;
			min_cost=Math.min(cost, min_cost);
		}
		System.out.println(min_cost);
	}
	
	public static int[][] readhw(int height, int width){
		int[][] hw = new int[height][width];
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<height;i++)
			for(int j=0;j<width;j++)
				hw[i][j]=sc.nextInt();
		return hw;
	}
}