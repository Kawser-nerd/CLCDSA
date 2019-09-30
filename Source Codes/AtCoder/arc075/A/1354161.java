import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main (String[] args){
	    Scanner scan = new Scanner(System.in);
	    int N = Integer.parseInt(scan.next());

	    ArrayList<Integer> SList = new  ArrayList<Integer>();
	    int seiseki = 0;
	    for(int i = 0; i < N; i++){
	    	int S = Integer.parseInt(scan.next());
	    	SList.add(S);
	    	seiseki = seiseki + S;
	    }
	    Collections.sort(SList);
	    
	    if(seiseki % 10 != 0){
	    	System.out.println(seiseki);
	    }else{
	    	for(int s : SList){
	    		if(s  % 10 != 0){
	    			seiseki = seiseki - s;
	    			System.out.println(seiseki);
	    			break;
	    		}
	    	}
	    	if(seiseki % 10 == 0){
	    		System.out.println(0);
	    	}
	    }
	}
}