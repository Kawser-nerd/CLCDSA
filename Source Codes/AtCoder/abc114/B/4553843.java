import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String S=sc.next();
		String[]x=new String[S.length()-2];
		for(int i=0;i<S.length()-2;i++) {
			x[i]=S.substring(i,i+3);//???????????????????
		}
		int []x2=new int[S.length()-2];
		for(int j=0;j<S.length()-2;j++) {
			x2[j]=Integer.parseInt(x[j]);
		}
		int answerX=Math.abs(753-x2[0]); 
		for(int k=1;k<S.length()-2;k++) {
			if(Math.abs(753-x2[k])<Math.abs(answerX)) {
				answerX=Math.abs(753-x2[k]);
				
			}
		}
		System.out.print(answerX);
		sc.close();
	}

}