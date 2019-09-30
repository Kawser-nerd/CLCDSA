import java.util.*;
class Main{
	public static void main(String [] argv){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 1; i <= n; i++){
			System.out.printf("Case #%d:\n", i);
			solve(sc);
		}
	}
	public static void solve(Scanner sc){
		int n = sc.nextInt();
		int [][] array = new int[n][3];
		int h_min = 1000000;
		int h_max = 1;
		int w_min = 1000000;
		int w_max = 1;
		int count = 0;
		for(int i = 0; i < n; i++){
			int h = sc.nextInt();
			int w = sc.nextInt();
			String x = sc.next();
			array[i][0] = h;
			array[i][1] = w;
			array[i][2] = x.equals("BIRD") ? 1 : 0;
			if(array[i][2] == 0){
				sc.next();
			}
			if(array[i][2] == 1){
				//System.out.println("B");
				if(h < h_min)
					h_min = h;
				if(h > h_max)
					h_max = h;
				if(w < w_min)
					w_min = w;
				if(w > w_max)
					w_max = w;
				count++;
			}

		}
		int m = sc.nextInt();
		for(int i = 0; i < m; i++){
			int h = sc.nextInt();
			int w = sc.nextInt();
			if(count == 0){
				boolean flag = false;
				for(int j = 0; j < n; j++){
					if(array[j][0] == h && array[j][1] == w){
						flag = true;
					}

				}
				if(flag){
					System.out.println("NOT BIRD");
				}else{
					System.out.println("UNKNOWN");
				}
			}else{
				if(h >= h_min && h <= h_max && w >= w_min && w <= w_max){
					System.out.println("BIRD");
				}else{
					boolean flag = false;
					int [] tmph = new int[2];
					int [] tmpw = new int[2];
					tmph[0] = h_min;
					tmph[1] = h_max;
					tmpw[0] = w_min;
					tmpw[1] = w_max;
					if(tmph[0] > h){
						tmph[0] = h;
					}
					if(tmph[1] < h){
						tmph[1] = h;
					}
					if(tmpw[0] > w){
						tmpw[0] = w;
					}
					if(tmpw[1] < w){
						tmpw[1] = w;
					}
					for(int j = 0; j < n; j++){
						if(array[j][2] == 0 && array[j][0] >= tmph[0] && array[j][0] <= tmph[1] && array[j][1] >= tmpw[0] && array[j][1] <= tmpw[1]){
							flag = true;
						}

					}
					if(flag){
						System.out.println("NOT BIRD");
					}else{
						System.out.println("UNKNOWN");
					}

				}
			}
		}
	}
}
