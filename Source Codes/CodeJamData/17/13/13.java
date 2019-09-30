import java.util.ArrayDeque;
import java.util.Scanner;

public class C {
	private static final int oo = 999999999;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		for(int t=1;t<=T;t++){
			int Hd = scan.nextInt(), Ad = scan.nextInt(),
				Hk = scan.nextInt(), Ak = scan.nextInt(),
				B = scan.nextInt(), D = scan.nextInt();
			
			boolean[][][][] memo = new boolean[Hd+1][Hk+1][101][101];
			
			
			memo[Hd][Hk][0][0] = true;
			
			int min = oo;
			
			ArrayDeque<Integer> q = new ArrayDeque<>();
			q.add(Hd);q.add(Hk);q.add(0);q.add(0);
			q.add(0);
			
			int att1 = 0, att2 = 0;
			while(!q.isEmpty()){
				
				int dragon = q.pollFirst(),
					knight = q.pollFirst(),
					buff = q.pollFirst(),
					debuff = q.pollFirst(),
					dist = q.pollFirst();
				
				if(dragon<=0){
					continue;
				}
				
				att1 = buff*B+Ad;
				att2 = -debuff*D+Ak;
				if(att2 < 0 )att2 = 0;
				
				//heal;
				if(!memo[Math.max(0, Hd-att2)][knight][buff][debuff]){
					memo[Math.max(0, Hd-att2)][knight][buff][debuff] = true;
					q.add(Math.max(0, Hd-att2));
					q.add(knight);
					q.add(buff);
					q.add(debuff);
					q.add(dist+1);
				}
				
				//buff
				if(buff<100 && !memo[Math.max(0, dragon-att2)][knight][buff+1][debuff]){
					memo[Math.max(0, dragon-att2)][knight][buff+1][debuff] = true;
					q.add(Math.max(0, dragon-att2));
					q.add(knight);
					q.add(buff+1);
					q.add(debuff);
					q.add(dist+1);
				}
				
				//att
				if(knight-att1<=0){
					min = dist+1;
					break;
				}
				else if(!memo[Math.max(dragon-att2, 0)][knight-att1][buff][debuff]){
					memo[Math.max(dragon-att2, 0)][knight-att1][buff][debuff] = true;
					q.add(Math.max(dragon-att2, 0));
					q.add(knight-att1);
					q.add(buff);
					q.add(debuff);
					q.add(dist+1);
				}
				
				att2 = -(debuff+1)*D+Ak;
				att2 = Math.max(att2, 0);
				if(debuff>=100)continue;
				if(!memo[Math.max(dragon-att2, 0)][knight][buff][debuff+1]){
					memo[Math.max(dragon-att2, 0)][knight][buff][debuff+1] = true;
					q.add(Math.max(dragon-att2, 0));
					q.add(knight);
					q.add(buff);
					q.add(debuff+1);
					q.add(dist+1);
				}
				
			}
			
			System.out.println("Case #"+t+": "+(min==oo?"IMPOSSIBLE":min));
			
		}
	}
}
