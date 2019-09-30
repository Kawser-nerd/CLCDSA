import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[] CDcase = new int[n+1];
		for(int i=0;i<n+1;i++){
		    CDcase[i] = i;
		}
		for(int i=0;i<m;i++){
		    int disc = sc.nextInt();
		    // find where disc is
		    int pos = 0;
		    for(int j=0;j<n+1;j++){
		        if(CDcase[j]==disc){
		            pos = j;
		        }
		    }
		    // swap
		    int temp = CDcase[0];
		    CDcase[0] = CDcase[pos];
		    CDcase[pos] = temp;
		}
		for(int i=1;i<n+1;i++){
		    System.out.println(CDcase[i]);
		}
	}
}