import java.util.*;
public class Main{
	public static class Node{
		char c;
		ArrayList<Character> to;
		boolean v;
		boolean use;
		boolean visit;
		boolean top;
		Node(){
			to = new ArrayList<Character>();
			use = false;
			visit = false;
			v = false;
			top = false;
		}
	}
	static Scanner sn = new Scanner(System.in);
	static int N = sn.nextInt();
	static String s1 = sn.next();
	static String s2 = sn.next();
	static Node[] alpha = new Node[26];
	static boolean flag = false;
	static boolean flag2 = false;
 	public static void main(String[] args){		
		for(int i = 0; i < 26; ++i){
			Node n = new Node();
			n.c = (char)('A' + i);
			alpha[i] = n;
		}
		for(int i = 0; i < N; ++i){
			char c1 = s1.charAt(i);
			char c2 = s2.charAt(i);
			if(!check_int(c1) && !check_int(c2)){
				if(c1 == c2){
					int ind = (int)c1 - (int)'A';
					alpha[ind].use = true;
					if(i == 0) alpha[ind].top = true;
				}
				else{
					int ind = (int)c1 - (int)'A';
					int ind2 = (int)c2 - (int)'A';
					alpha[ind].use = true;
					alpha[ind2].use = true;
					alpha[ind].to.add(c2);
					alpha[ind2].to.add(c1);
					if(i == 0){
						alpha[ind].top = true;
						alpha[ind2].top = true;
					}
				}
			}
			else if(!check_int(c1) && check_int(c2)){
				int ind = (int)c1 - (int)'A';
				alpha[ind].use = true;
				alpha[ind].v = true;
			}
			else if(check_int(c1) && !check_int(c2)){
				int ind2 = (int)c2 - (int)'A';
				alpha[ind2].use = true;
				alpha[ind2].v = true;
			}
		}
		
		long ans = 1L;
		for(int i = 0; i < 26; ++i){
			if(!alpha[i].use || alpha[i].visit) continue;			
			flag = false;
			flag2 = false;
			alpha[i].visit = true;
			solve(alpha[i]);
			if(flag2 && !flag) ans *= 9;
			else if(!flag2 && !flag) ans *= 10;
		}
		System.out.println(ans);
	}
	
	public static void solve(Node node){
		if(node.v) flag = true;
		if(node.top) flag2 = true;
		for(int i = 0; i < node.to.size(); ++i){
			int next = node.to.get(i) - 'A';
			if(alpha[next].visit) continue;
			alpha[next].visit = true;			
			solve(alpha[next]);
		}
	}
	
	public static boolean check_int(char c){
		if(c == '0' || c == '1'|| c == '2'|| c == '3'|| c == '4'|| c == '5'|| c == '6'|| c == '7'|| c == '8'|| c == '9'){
			return true;
		}
		else{
			return false;
		}
	}
}