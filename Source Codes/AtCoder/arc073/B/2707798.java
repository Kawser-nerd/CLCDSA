import java.io.*;
import java.util.*;

class Main{
    public static void main(String[] args){
        solve();
    }

    public static void solve(){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int weight = sc.nextInt();
        int[] w = new int[n];
        int[] v = new int[n];
        int[] size = new int[4];
        long[][] count = new long[4][n+1];
        for(int i=0;i<n;i++){
        	w[i] = sc.nextInt();
        	v[i] = sc.nextInt();
        }
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        for(int i=0;i<4;i++){
        	list.add(new ArrayList<Integer>());
        }
        for(int i=0;i<n;i++){
        	ArrayList<Integer> l = list.get(w[i] - w[0]);
        	l.add(v[i]);
        }
		for(int i=0;i<4;i++){
			ArrayList<Integer> l = list.get(i);
			Collections.sort(l);
			size[i] = l.size();
        }
        for(int i=0;i<4;i++){
        	ArrayList<Integer> l = list.get(i);
        	for(int j=0;j<=size[i];j++){
        		if(j==0){
        			count[i][j] = 0;
        		}
        		else{
        			count[i][j] = count[i][j-1] + (long)l.get(l.size()-j);
        		}
        	}
        }

        long ans = 0;
        for(int i=0;i<=size[0];i++){
        	if(i*w[0]>weight){
        		break;
        	}
        	for(int j=0;j<=size[1];j++){
        		if(i*w[0]+j*(w[0]+1)>weight){
        			break;
        		}
        		for(int k=0;k<=size[2];k++){
        			if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)>weight){
        				break;
        			}
        			int l = (int)Math.min((weight-i*w[0]-j*(w[0]+1)-k*(w[0]+2))/(w[0]+3), size[3]);
        			ans = (long)Math.max(ans, count[0][i]+count[1][j]+count[2][k]+count[3][l]);
        		}
        	}
        }
        System.out.println(ans);
    }
}