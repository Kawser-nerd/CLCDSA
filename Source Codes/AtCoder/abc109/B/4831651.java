import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<String> list = new ArrayList<String>();
		int i = 0;
		String hoge = sc.next();
		list.add(hoge);
		for(i = 1; i < n; i++){
			String w = sc.next();
			hoge = hoge.substring(hoge.length()-1,hoge.length());
			String hoge2 = w.substring(0,1);
			if(!hoge.equals(hoge2)){
				break;
			}else if(list.indexOf(w) > -1){
				break;
			}else{
				list.add(w);
				hoge = w;
			}
		}
		System.out.print(i == n?"Yes":"No");
	}
}