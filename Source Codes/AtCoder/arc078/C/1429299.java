import java.io.*;
import java.util.*;
 
public class Main{

	Scanner sc = new Scanner(System.in);
	public boolean pln(long val){
		System.out.print('?');
		System.out.print(' ');
		System.out.println(val);
		return get();
	}
	
	public boolean get(){
		return sc.next().equals("Y");
	}
	
	public void solve(){
		long num = 1000000000;
		
		
		if(pln(num)){
			long num2 = 9;
			num = 1;
			while(true){
				if(pln(num2)){
					break;
				}
				num *= 10;
				num2 = (num2 * 10) + 9;
			}
			System.out.println("! " + num);
		}else{
			int digit = 9;
			while(digit > 1){
				num /= 10;
				if(pln(num)){
					break;
				}
				digit--;
			}
			
			long ans = 0;
			for(int i = 0; i < digit - 1; i++){
				if(pln(ans * 10 + 5)){
					if(pln(ans * 10 + 7)){
						if(pln(ans * 10 + 8)){
							if(pln(ans * 10 + 9)){
								ans = ans * 10 + 9;
							}else{
								ans = ans * 10 + 8;
							}
						}else{
							ans = ans * 10 + 7;
						}
					}else{
						if(pln(ans * 10 + 6)){
							ans = ans * 10 + 6;
						}else{
							ans = ans * 10 + 5;
						}
					}
				}else{
					if(pln(ans * 10 + 3)){
						if(pln(ans * 10 + 4)){
							ans = ans * 10 + 4;
						}else{
							ans = ans * 10 + 3;
						}
					}else{
						if(pln(ans * 10 + 2)){
							ans = ans * 10 + 2;
						}else{
							if(pln(ans * 10 + 1)){
								ans = ans * 10 + 1;
							}else{
								ans = ans * 10 + 0;
							}
						}
					}
				}
			}
			
			if(!pln(ans * 100 + 40)){
				if(!pln(ans * 100 + 60)){
					if(!pln(ans * 100 + 70)){
						if(!pln(ans * 100 + 80)){
							ans = ans * 10 + 9;
						}else{
							ans = ans * 10 + 8;
						}
					}else{
						ans = ans * 10 + 7;
					}
				}else{
					if(!pln(ans * 100 + 50)){
						ans = ans * 10 + 6;
					}else{
						ans = ans * 10 + 5;
					}
				}
			}else{
				if(!pln(ans * 100 + 20)){
					if(!pln(ans * 100 + 30)){
						ans = ans * 10 + 4;
					}else{
						ans = ans * 10 + 3;
					}
				}else{
					if(!pln(ans * 100 + 10)){
						ans = ans * 10 + 2;
					}else{
						if(!pln(ans * 100)){
							ans = ans * 10 + 1;
						}else{
							ans = ans * 10 + 0;
						}
					}
				}
			}
			System.out.println("! " + ans);
		}
		
	}
	
	public static void main(String[] args){
		new Main().solve();
	}
}