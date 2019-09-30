import java.util.*;
import java.lang.*;
import java.io.*;
public class Main {
    public static void main(String[] args) {
 
    	final int INF = 10000000;
 
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int K = sc.nextInt();
 
        int startH=-1,startW=-1;
        boolean open[][] = new boolean[H][W];
 
        for(int h=0;h<H;h++){
        	String row = sc.next();
        	for(int w=0;w<W;w++){
        		if(row.charAt(w)=='S'){
        			open[h][w]=true;
        			startH=h;
        			startW=w;
        		}else open[h][w]=(row.charAt(w)=='.');
        	}
        }
        //input end
 
        int[][] directDistance = new int[H][W];
        for(int h=0;h<H;h++){
        	for(int w=0;w<W;w++){
        		directDistance[h][w]=INF;
        	}
        }
        directDistance[startH][startW]=0;
 
        ArrayList<Integer> visitedH =new ArrayList<>();
        ArrayList<Integer> visitedW =new ArrayList<>();
        visitedH.add(startH);
        visitedW.add(startW);
 
        while(!visitedH.isEmpty()){
        	int h = visitedH.remove(0);
        	int w = visitedW.remove(0);
        	
        	if(h>0 && open[h-1][w] && directDistance[h-1][w]>1+directDistance[h][w]){
        		directDistance[h-1][w] = 1+directDistance[h][w];
        		visitedH.add(h-1);
        		visitedW.add(w);
        	}
        	if(h<H-1 && open[h+1][w] && directDistance[h+1][w]>1+directDistance[h][w]){
        		directDistance[h+1][w] = 1+directDistance[h][w];
        		visitedH.add(h+1);
        		visitedW.add(w);
        	}        	
        	if(w>0 && open[h][w-1] && directDistance[h][w-1]>1+directDistance[h][w]){
        		directDistance[h][w-1] = 1+directDistance[h][w];
        		visitedH.add(h);
        		visitedW.add(w-1);
        	}  
        	if(w<W-1 && open[h][w+1] && directDistance[h][w+1]>1+directDistance[h][w]){
        		directDistance[h][w+1] = 1+directDistance[h][w];
        		visitedH.add(h);
        		visitedW.add(w+1);
        	}  
        }
 
        int ans = INF;
        for(int h = Math.max(0,startH-K);h<=Math.min(H-1,startH+K);h++){
        	for(int w = Math.max(0,startW-K);w<=Math.min(W-1,startW+K);w++){
        		if(directDistance[h][w]<=K){//first step: go to [h][w]
        			//and then go straight for the closest wall
        			
        			int toWall = Math.min(Math.min(h,H-h-1),Math.min(w,W-w-1));
        			int magic = 1+(toWall+K-1)/K;
        			if(magic<ans) ans = magic;
        		}
        	}
        }
 
 
        System.out.println(ans);
    }
}