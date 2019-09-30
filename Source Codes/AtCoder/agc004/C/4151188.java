import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int h=sc.nextInt(),w=sc.nextInt();
		int[][] aka=new int[h][w];
		int[][] ao=new int[h][w];
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(i%2==0){
					if(j==0){
						aka[i][j]=1;
					}else{
						ao[i][j]=1;
					}
				}else{
					if(j==(w-1)){
						ao[i][j]=1;
					}else{
						aka[i][j]=1;
					}
				}
			}
			String str=sc.next();
			for(int j=0;j<w;j++){
				if(str.charAt(j)=='#'){
					aka[i][j]=1;
					ao[i][j]=1;
				}
			}
		}
		pl(aka);
		System.out.println();
		pl(ao);
	}
	static void pl(int[][] ta){
		for(int i=0;i<ta.length;i++){
			for(int j=0;j<ta[0].length;j++){
				System.out.print((ta[i][j]==1)?'#':'.');
			}
			System.out.println();
		}
	}
}