import java.io.*;
import java.util.*;

class Main{
	public static void main(String[] args){
		solve();
	}
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int x = sc.nextInt()+10000;
		int y = sc.nextInt()+10000;
		int[] xdp = new int[20000];
		int[] ydp = new int[20000];
		int xnow = 1;
		int ynow = 1;
		xdp[10000] = 1;
		ydp[10000] = 1;
		boolean flag = true;
		boolean judge = true;
		int count = 0;
		for(int j=0;j<s.length();j++){
			if(s.charAt(j)=='F'){
				count++;
			}
			else{
				ArrayList<Integer> list = new ArrayList<Integer>();
				if(count!=0){
						if(flag){
							if(judge){
								for(int i=0;i<20000;i++){
									if(xdp[i] == xnow){
										list.add(i);
									}
								}
								for(int i=0;i<list.size();i++){
									int z = list.get(i);
									xdp[z+count] = xnow + 1;
								}
							}
							else{
								for(int i=0;i<20000;i++){
									if(xdp[i] == xnow){
										list.add(i);
									}
								}
								for(int i=0;i<list.size();i++){
									int z = list.get(i);
									xdp[z+count] = xnow + 1;
									xdp[z-count] = xnow + 1;
								}
							}
							xnow++;
						}
						else{
							for(int i=0;i<20000;i++){
								if(ydp[i] == ynow){
									list.add(i);
								}
							}
							for(int i=0;i<list.size();i++){
								int z = list.get(i);
								ydp[z+count] = ynow + 1;
								ydp[z-count] = ynow + 1;
							}
							ynow++;
						}
				}
				flag = !flag;
				judge = false;
				count = 0;
			}
		}
		ArrayList<Integer> list = new ArrayList<Integer>();
		if(count!=0){
						if(flag){
							if(judge){
								for(int i=0;i<20000;i++){
									if(xdp[i] == xnow){
										list.add(i);
									}
								}
								for(int i=0;i<list.size();i++){
									int z = list.get(i);
									xdp[z+count] = xnow + 1;
								}
							}
							else{
								for(int i=0;i<20000;i++){
									if(xdp[i] == xnow){
										list.add(i);
									}
								}
								for(int i=0;i<list.size();i++){
									int z = list.get(i);
									xdp[z+count] = xnow + 1;
									xdp[z-count] = xnow + 1;
								}
							}
							xnow++;
						}
						else{
							for(int i=0;i<20000;i++){
								if(ydp[i] == ynow){
									list.add(i);
								}
							}
							for(int i=0;i<list.size();i++){
								int z = list.get(i);
								ydp[z+count] = ynow + 1;
								ydp[z-count] = ynow + 1;
							}
							ynow++;
						}
				}


		if(xdp[x] == xnow && ydp[y] == ynow){
			System.out.println("Yes");
		}
		else{
			System.out.println("No");
		}
	}
}