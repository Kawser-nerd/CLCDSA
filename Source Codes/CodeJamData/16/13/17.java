import java.util.*;

public class Solution{

	public static int search(int from, int[] bffs, ArrayList<ArrayList<Integer>> likesMe, int exclude)
	{
		int best = 0;
		for(int kid : likesMe.get(from))
		{
			if(kid == exclude) continue;
			else
			{
				int ch = search(kid, bffs, likesMe, -1);
				if(ch > best) best = ch;
			}
		}
		return best+1;
	}

	public static void main(String[] args){
	
		Scanner in = new Scanner(System.in);
		
		int cas = in.nextInt();
		
		for(int c = 1; c <= cas; c++)
		{
			System.out.print("Case #" + c + ": ");
			int DISCONT_STRAT = 0;
			int CYCLE_STRAT_MAX = 0;
			int nkids = in.nextInt();
			int[] bffs = new int[nkids];
			ArrayList<ArrayList<Integer>> likesMe = new ArrayList<ArrayList<Integer>>();
			for(int i = 0; i < nkids; i++)
			{
				likesMe.add(new ArrayList<Integer>());
			}
			for(int i = 0; i < nkids; i++)
			{
				bffs[i] = in.nextInt()-1;
				likesMe.get(bffs[i]).add(i);
			}
			for(int i = 0; i < nkids; i++)
			{
				for(int kid : likesMe.get(i))
				{
					if(likesMe.get(kid).contains(i) && i < kid)
					{
						int LAYERS_DOWN = 0;
						//begin dfs
							int r = search(i, bffs, likesMe, kid);

							int l = search(kid, bffs, likesMe, i);
						DISCONT_STRAT += (l + r);
					}
				}
			}
			//System.out.println(DISCONT_STRAT);
			boolean[] visited = new boolean[nkids];
			int[] asd = new int[nkids];
			for(int ml = 0; ml < nkids; ml++)
			{
				Arrays.fill(visited, false);
				int ne = ml;
				int cccc = 0;
				visited[ne] = true;
				cccc++;
				asd[ne] = cccc;
				while(!visited[bffs[ne]])
				{
					ne = bffs[ne];
					visited[ne] = true;
					cccc++;
					asd[ne] = cccc;
				}
				int blh = asd[ne]-asd[bffs[ne]]+1;
				if(blh > CYCLE_STRAT_MAX) CYCLE_STRAT_MAX = blh;
			}
			System.out.println(Math.max(CYCLE_STRAT_MAX, DISCONT_STRAT));
		}
	}
}