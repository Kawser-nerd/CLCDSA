import java.util.*;

public class Main {
    public static int r,g,b,total;
    public static int ENOUGH_BIG = (int)Math.pow(10,9);
    public static void main(String[] args){
	Scanner sc = new Scanner(System.in);
	// ?????
	r = sc.nextInt();
	g = sc.nextInt();
	b = sc.nextInt();
        total = r + g + b;

	int table[][] = new int[1000][1000];
	//total???????????????
	for(int i = 0; i < 1000; ++i){
	    for(int j = 0; j < 1000; ++j){
		if(j == total){
		    table[i][j] = 0;
		} else {
		    table[i][j] = ENOUGH_BIG;
		}
	    }
	}

	for(int i = 1; i < 999; ++i){
	    for(int j = 0; j < total; ++j){
		table[i][j] = Math.min(table[i-1][j], table[i-1][j+1] + cost(i,j+1));
	    }
	}

	
	int minScore = ENOUGH_BIG;
	for(int i = 0; i < 1000; ++i){
	    minScore = Math.min(minScore, table[i][0]);
	}
	System.out.println(minScore);
    }

    //???????j?????i??????????????
    public static int cost(int i, int j){
	int result;
	if(j > g + b){
	    result = Math.abs(i - 400);
	} else if(j > b){
	    result = Math.abs(i - 500);
	} else {
	    result = Math.abs(i - 600);
	}
	return result;
    }
}