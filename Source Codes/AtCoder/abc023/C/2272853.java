import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class Main{
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);

		int r=s.nextInt(),c=s.nextInt(),k=s.nextInt();
		int[] cx=new int[r],cy=new int[c],ccx=new int[k+1],ccy=new int[k+1];

		Map<Integer,List<Integer>> p=new HashMap<>();
		for(int n=s.nextInt();n>0;--n){
			int X=s.nextInt()-1,Y=s.nextInt()-1;
			p.computeIfAbsent(X,(i)->new ArrayList<>())
					.add(Y);
			cx[X]++;
			cy[Y]++;
		}

		for(int X:cx)
			if(X<k+1)
				ccx[X]++;
		for(int Y:cy)
			if(Y<k+1)
				ccy[Y]++;
		/*
		System.err.println(Arrays.toString(x));
		System.err.println(Arrays.toString(y));
		System.err.println(Arrays.toString(cx));
		System.err.println(Arrays.toString(cy));
		*/
		long res=0;
		for(int x=0;x<r;++x){
			int need=k-cx[x];
			if(need<0)
				continue;
			int CY=ccy[need];
			if(p.containsKey(x)){
				for(int y:p.get(x)){
					if(cy[y]-1==need)
						++res;
					if(cy[y]==need)
						--CY;
				}
			}
			res+=CY;
		}
		System.out.println(res);
	}
}