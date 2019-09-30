import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int h=sc.nextInt(),w=sc.nextInt();
		int[][] ta=new int[h][w];
		for(int i=0;i<h;i++){
			String str=sc.next();
			for(int j=0;j<w;j++) ta[i][j]=(int)(str.charAt(j)-'a');
		}
		
		int[] jun=new int[h];
		for(int i=0;i<h;i++) jun[i]=i;
		int[][] nta=new int[h][w];
		for(int k=0;k<100000;k++){
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++) nta[jun[i]][j]=ta[i][j];
			}
			if(check(nta)){
				System.out.println("YES");
				return;
			}
			shuffle(jun);
		}
		System.out.println("NO");
	}
	static boolean check(int[][] ta){
		int h=ta.length,w=ta[0].length;
		boolean cent=(w%2==1)?false:true;
		boolean res=true;
		boolean[] jun=new boolean[w];
		for(int i=0;i<w;i++){
			if(jun[i]) continue;
			int j=0;
			for(;j<w;j++){
				if(jun[j]) continue;
				if(i==j) continue;
				boolean itti=true;
				for(int k=0;k<h;k++){
					if(ta[k][i]!=ta[h-k-1][j]){
						itti=false;
						break;
					}
				}
				if(itti){
					break;
				}
			}
			if(j<w){
				jun[i]=true;
				jun[j]=true;
			}else{
				boolean taisyo=true;
				for(int k=0;k<h;k++){
					if(ta[k][i]!=ta[h-k-1][i]){
						taisyo=false;
						break;
					}
				}
				if(taisyo && !cent){
					cent=true;
				}else return false;
			}
		}
		return true;
	}
	public static void shuffle(int[] array){
		for (int i = array.length - 1; i > 0; i--) {
			int index = (int)(Math.random()*i);
			int tmp = array[index];
			array[index] = array[i];
			array[i] = tmp;
		}
	}
}