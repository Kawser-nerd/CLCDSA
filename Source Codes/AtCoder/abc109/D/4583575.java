import java.util.Scanner;
import java.util.ArrayList;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int h = sc.nextInt();
		int w = sc.nextInt();
		int[][] map = new int[h][w];
		ArrayList<String> list=new ArrayList<>();
		int sum=0;
		for(int i = 0; i<h; i++){
			for(int j = 0; j<w; j++){
				map[i][j]=sc.nextInt();
			}
		}
		boolean jud=false;
		for(int i = 0; i<h; i++){
			if(i%2==0){
				for(int j = 0; j<w; j++){
					if(jud){
						if(j==0){
							list.add(i+" "+(j+1)+" "+(i+1)+" "+(j+1));
							sum++;
						}else{
							list.add((i+1)+" "+j+" "+(i+1)+" "+(j+1));
							sum++;
						}
					}
					if(map[i][j]%2==1){
						jud=!jud;
					}
				}
			}else{
				for(int j = w-1; j>=0; j--){
					if(jud){
						if(j==w-1){
							list.add(i+" "+(j+1)+" "+(i+1)+" "+(j+1));
							sum++;
						}else{
							list.add((i+1)+" "+(j+2)+" "+(i+1)+" "+(j+1));
							sum++;
						}
					}
					if(map[i][j]%2==1){
						jud=!jud;
					}
				}
			}
		}
		System.out.println(sum);
		for(String i:list){
			System.out.println(i);
		}
	}
}