import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

import org.jgrapht.Graph;
import org.jgrapht.graph.DefaultEdge;
import org.jgrapht.graph.SimpleDirectedGraph;
import org.jgrapht.graph.SimpleGraph;
import org.jgrapht.traverse.BreadthFirstIterator;


public class Main {
	public static void main(String[] args) throws Exception{
		
		Scanner scanner = new Scanner(new File("D-large.in"));
		
		PrintStream writer = new PrintStream(new File("output.large"));
		int T = scanner.nextInt();
		
		
		
		for (int c = 0; c < T; c++){
			int[]  keys =  new int[201];
			Set<Integer>[] keyToChest = new Set[201];
			for (int i= 1; i < 201; i++){
				keyToChest[i] = new HashSet<Integer>();
			}
			
			int K = scanner.nextInt();
			int N = scanner.nextInt();
			HashMap<Integer, Integer> keysInHand = new HashMap<Integer, Integer>(); 
			
			HashMap<Integer, Integer>[] keysInChest = new HashMap[N+1];
			boolean[] chestOpened = new boolean[N+1];
			int[] chestAccessKeys = new int[N+1];
			for (int i = 1; i < N+1; i++){
				keysInChest[i] = new HashMap<Integer, Integer>();
			}
			
			for (int i= 0; i < K; i++){
				int key = scanner.nextInt(); 
				keys[key] ++;
				increment(keysInHand, key);
			}
			
			for (int i= 0; i < N; i++){
				int accessKey = scanner.nextInt();
				int M = scanner.nextInt();
				keyToChest[accessKey].add(i+1); 
				chestAccessKeys[i+1] = accessKey;
				while (M-- > 0){
					int key = scanner.nextInt();
					increment(keysInChest[i+1], key);
				}
			}

			// build graph 
			// Graph
			Graph<Integer, DefaultEdge> g = buildGraph(N, keysInChest, keyToChest, keysInHand);
			
			
			ArrayList<Integer> ret = new ArrayList<Integer>();
			
			// while still there are more chests
			while(g.vertexSet().size() > 0){
				
				
			    // find the first remaining chest that I can open with one of the keys
				int chest = 0;
				while((chest = findNextClosedChest(chest, chestOpened)) != -1){
					// 	if *open that does not cause problem, open it*
					if (allowOpen(chest, keysInHand, keyToChest, chestAccessKeys, keysInChest, (SimpleDirectedGraph<Integer, DefaultEdge>)g))
						{
							open(chest, keysInHand, keyToChest, chestAccessKeys, chestOpened, keysInChest, g);
//							System.out.printf("Open chest %d\n", chest);
							ret.add(chest);
							break;
						}
					
					// else find the next remaining chest to open and do the same test.
				}
				
				// if i can open none of the  chest, then return false
				if (chest == -1)
					break;
			}
			
			if (g.vertexSet().size() > 0){
				System.out.printf("Case #%d: IMPOSSIBLE\n", c+1);
				writer.printf("Case #%d: IMPOSSIBLE\n", c+1);
				
			}
			else
			{
				System.out.printf("Case #%d:", c+1);
				writer.printf("Case #%d:", c+1);
				for (int ch : ret){
					System.out.printf(" %d", ch);
					writer.printf(" %d", ch);
				}
				System.out.println();
				writer.println();
			}

		}
	}
	
	static void open(int chest, 
			HashMap<Integer, Integer> keysInHand,
			Set<Integer>[] keyToChest,
			int[] chestAccessKeys,
			boolean[] chestOpened,
			HashMap<Integer, Integer>[] keysInChest ,
			Graph<Integer, DefaultEdge> g){
		
		int accessKey = chestAccessKeys[chest];
		chestOpened[chest] = true;
		HashMap<Integer, Integer> newKeys = keysInChest[chest];
		
		for (int newKey: newKeys.keySet()){
			if (keysInHand.containsKey(newKey)){
				keysInHand.put(newKey, keysInHand.get(newKey) + newKeys.get(newKey));
			}
			else
				keysInHand.put(newKey, newKeys.get(newKey));
		}
		
		// remove the old key
		if (keysInHand.get(accessKey) == 1)
			keysInHand.remove(accessKey);
		else
			keysInHand.put(accessKey, keysInHand.get(accessKey) - 1);
		
		
		// remove the chest node. 
		g.removeVertex(chest);
		
	}
	
	static boolean allowOpen(int chest, 
			HashMap<Integer, Integer> keysInHand,
			Set<Integer>[] keyToChest,
			int[] chestAccessKeys,
			HashMap<Integer, Integer>[] keysInChest ,
			SimpleDirectedGraph<Integer, DefaultEdge> g){
		
		int accessKey = chestAccessKeys[chest];
		if (!keysInHand.containsKey(accessKey))
			return false;
		
		if (keysInHand.get(accessKey) > 1){
			return true;
		}
		
		boolean moreChestsWithSameKey = false;
		for (int ch : g.vertexSet()){
			if (ch != chest && chestAccessKeys[ch] == accessKey){
				moreChestsWithSameKey = true;
				break;
			}
		}
		
		if (!moreChestsWithSameKey)
			return true;
		
		// we wnat to remve the opened chest, 
		g = (SimpleDirectedGraph<Integer, DefaultEdge>) g.clone();
		
		// and remve the key, and add keys from the removed chest
		keysInHand = (HashMap<Integer, Integer>)keysInHand.clone();
		keysInHand.remove(accessKey);
		keysInHand.putAll(keysInChest[chest]);
		g.removeVertex(chest);
		
		// and add the node 0, with keys serving edges
		g.addVertex(0);
		for (int key : keysInHand.keySet()){
			for (int ch : keyToChest[key])
			{
				if (g.vertexSet().contains(ch))
					g.addEdge(0, ch);
			}
		}
		
		// do a bfs walk from 0, to see if any chest with same access
		// key can be found. 
		
		BreadthFirstIterator<Integer, DefaultEdge> bfs = new BreadthFirstIterator<Integer, DefaultEdge>(g, 0);
		while(bfs.hasNext()){
			int ch = bfs.next();
			if (chestAccessKeys[ch] == accessKey){
				return true;
			}
		}
		return false;
		
		// we need to restore the graph as well.
		
		// if not found return false;
		
		// else return true;
		
		// open it
		
		
	}

	static int findNextClosedChest(int chest, boolean[] chestOpened){
		for (int j = chest+1; j < chestOpened.length; j++){
			if (!chestOpened[j])
				return j;
		}
		return -1;
	}
	
	static Graph<Integer, DefaultEdge> buildGraph(
			int n, HashMap<Integer, Integer>[] keysInChest, 
			Set<Integer>[] keyToChest,
			HashMap<Integer, Integer> keysInHand
			){
		Graph<Integer, DefaultEdge> g = new SimpleDirectedGraph<Integer, DefaultEdge>(DefaultEdge.class);
		for (int i= 1; i <=n ; i++){
			g.addVertex(i);
		}
//		
//		for (int key: keysInHand.keySet()){
//			for (int nextChest : keyToChest[key])
//				g.addEdge(0, nextChest);
//		}
		
		for (int i= 1; i <= n; i++){
			for (int key : keysInChest[i].keySet()){
				for (int nextChest : keyToChest[key]){
//					System.out.printf("adding %d: %d\n", i, nextChest);
					if (i != nextChest)
						g.addEdge(i, nextChest);
				}
			}
		}

		
		return g;
		
	}
	
	static void increment(HashMap<Integer, Integer> map, int i){
		if (map.containsKey(i)){
			map.put(i, map.get(i)+1);
		}
		else
			map.put(i, 1);
	}
	
	static void graphDemo(){
		
		Graph<String, DefaultEdge> graph = new SimpleDirectedGraph<String, DefaultEdge>(DefaultEdge.class);
		
		
		graph.addVertex("a");
		graph.addVertex("b");
		graph.addVertex("c");
		
		graph.addEdge("a", "b");
		graph.addEdge("b", "c");
		
		BreadthFirstIterator<String, DefaultEdge> it = new BreadthFirstIterator<String, DefaultEdge>(graph);
		while(it.hasNext()){
			System.out.println(it.next());
		}
	}
	
}
