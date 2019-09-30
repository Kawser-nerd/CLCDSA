import java.util.*;

public class Main {
	long cuenta(int numero, int base, int ultimo, int[] vistos){
		if(numero == 0) return 1;
		if(numero < 0) return 0;
		if(dp[numero][base][ultimo].containsKey(vistos))
			return (Long)dp[numero][base][ultimo].get(vistos);
		
		long ret = 0;
		for(int x = 1; x < ultimo; x++){
			char[] numerote = Integer.toString(x, base).toCharArray();
			int[] sig = vistos.clone();
			boolean sirve = true;
			for(int j = 0; j < numerote.length; j++){
				if((vistos[j] & (1 << (numerote[numerote.length - j - 1]- '0'))) != 0)
					sirve = false;
				else sig[j] |= (1 << (numerote[numerote.length - j - 1]- '0'));
			}
			if(!sirve) continue;
			ret += cuenta(numero - x, base, x, sig);
			ret = ret % modulo;
		}
		dp[numero][base][ultimo].put(vistos, (Long)ret);
		return ret;
	}
	HashMap[][][] dp = new HashMap[102][11][102];
	
	public Main(){
		inicializa();
		
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int caso = 1; caso <= t; caso++){
			int n = in.nextInt();
			int base = in.nextInt();
			int[] mascara = new int[8];
			Arrays.fill(mascara, 0);
			System.out.println("Case #" + caso + ": " + cuenta(n, base, n + 1, mascara));
		}
	}
	void inicializa(){
		for(int i = 0; i < 102; i++) for(int j = 0; j < 11; j++)
			for(int k = 0; k < 102; k++) dp[i][j][k] = new HashMap();
	}
	long modulo = 1000000007;
	public static void main(String[] args){
		new Main();
	}
	
}
