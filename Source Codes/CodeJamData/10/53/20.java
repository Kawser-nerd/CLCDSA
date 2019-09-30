package y2010.round3.c;

import java.util.Scanner;

public class C {
	
	Scanner in;	
	
	public C() {	
		
		int CASE = 1;
		
		String[] name = {"sample", "small", "large"};		
		System.setIn(this.getClass().getResourceAsStream(name[CASE]+".in"));			
		in = new Scanner(System.in);
		
		int _t = in.nextInt();
		for(int _l=1;_l<=_t;_l++){
			int[] x = new int[3000001];
			
			int min = 3000001;
			int c = in.nextInt();
			for(int i=0;i<c;i++){
				int p = in.nextInt()+1500000;
				int v = in.nextInt();
				
				x[p] = v;			
				min = Math.min(min, p);				
			}
			
			//System.out.println(min);
			
			int times = 0;
			while(true){
				boolean finish =true;
				for(int i=min;i<x.length;i++){
					if(x[i]>1){
						finish = false;
						x[i-1] += 1;
						x[i+1] += 1;
						x[i] -= 2;
						
						times ++;
						if(x[i-1]>1)
							min = i-1;
						break;
					}					
				}
				
				if(finish)
					break;
				
				
				
			}
			
//			System.out.println(times);
			
		
			String ans = ""+times;
			System.out.printf("Case #%d: %s\n", _l, ans);		
		}
		
	}

	public static void main(String[] args) {
		new C();
	}

}
