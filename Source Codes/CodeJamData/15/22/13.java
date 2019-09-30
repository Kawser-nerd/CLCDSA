import java.io.*;
import java.util.*;
import java.math.*;

public class NosyNeighbors {
	static int c;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("out.out"));
		int t = Integer.parseInt(br.readLine());
		for(c = 1; c <= t; c++){
			bw.write("Case #" + c + ": ");
			String line = br.readLine();
			String[] fields = line.split(" ");
			int w = Integer.parseInt(fields[0]);
			int h = Integer.parseInt(fields[1]);
			int n = Integer.parseInt(fields[2]);
			// System.out.println(w + " " + h + " " + n);
			// if(n <= (w * h + 1) / 2){
			// 	System.out.println(0);
			// 	bw.write(0 + "\n");
			// 	continue;
			// }
			boolean[][] occ = new boolean[w + 2][h + 2];
			int[][] arr = new int[w + 2][h + 2];
			for(int i = 1; i <= w; i++){
				for(int j = 1; j <= h; j++){
					occ[i][j] = true;
				}
			}
			for(int i = 1; i <= w; i++){
				for(int j = 1; j <= h; j++){
					if(occ[i+1][j]) arr[i][j]++;
					if(occ[i-1][j]) arr[i][j]++;
					if(occ[i][j+1]) arr[i][j]++;
					if(occ[i][j-1]) arr[i][j]++;
				}
			}
			// for(int i = 1; i <= w; i++){
			// 	for(int j = 1; j <= h; j++){
			// 		System.out.print(arr[i][j] + " ");
			// 	}System.out.println();
			// }System.out.println();

			for(int k = w * h; k > n; k--){
				int max = -1;
				int x = -1;
				int y = -1;
				for(int i = 1; i <= w; i++){
					boolean breaker = false;
					for(int j = 1; j <= h; j++){
						if(occ[i][j] && arr[i][j] > max){
							max = arr[i][j];
							x = i;
							y = j;
						}
						if(max == 4){
							breaker = true;
							break;
						}
					}
					if(breaker){
						break;
					}
				}
				arr[x][y] = 0;
				occ[x][y] = false;
				if(occ[x+1][y]) arr[x+1][y]--;
				if(occ[x-1][y]) arr[x-1][y]--;
				if(occ[x][y+1]) arr[x][y+1]--;
				if(occ[x][y-1]) arr[x][y-1]--;
			}
			// for(int i = 1; i <= w; i++){
			// 	for(int j = 1; j <= h; j++){
			// 		System.out.print(arr[i][j] + " ");
			// 	}System.out.println();
			// }System.out.println();

			int count = 0;
			for(int i = 1; i <= w; i++){
				for(int j = 1; j <= h; j++){
					count += arr[i][j];
				}
			}
			count /= 2;
			n -= (w * h + 1) / 2;
			int count2 = 0;
			if(n < 0){
			// if(n <= (w * h + 1) / 2){
				// System.out.println(0);
				bw.write(0 + "\n");
				continue;
			}
			int sides = ((int)(w / 2)) * 2 + ((int)(h / 2)) * 2;
			if(n <= sides){
				count2 += n * 3;
				bw.write(Math.min(count, count2) + "\n");
				continue;
			}
			else{
				count2 += sides * 3;
				count2 -= sides;
			}
			count2 += 4 * n;
			
			bw.write(Math.min(count, count2) + "\n");
		}
		br.close();
		bw.close();
	}



}