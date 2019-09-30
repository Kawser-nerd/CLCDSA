import java.util.*;
import java.util.Map.Entry;

class Treasure
{
  public static void main(String... args)
  {
    Scanner sc = new Scanner(System.in);
    int tests = sc.nextInt();
    for (int test = 1; test <= tests; ++test)
    {
      int k = sc.nextInt();
      int n = sc.nextInt();
      KeySet startKeys = new KeySet();
      for (int i = 0; i < k; ++i)
      {
        startKeys.addKey(sc.nextInt());
      }
      Chest[] chests = new Chest[n];
      for (int i = 0; i < n; ++i)
      {
        int key = sc.nextInt();
        int numContained = sc.nextInt();
        KeySet containedKeys = new KeySet();
        for (int j = 0; j < numContained; ++j)
        {
          containedKeys.addKey(sc.nextInt());
        }
        chests[i] = new Chest(i + 1, key, containedKeys);
      }
      List<Integer> order = solve(startKeys, chests);
      System.out.print("Case #" + test + ":");
      if (order == null)
      {
        System.out.println(" IMPOSSIBLE");
      }
      else
      {
        for (Integer i : order)
        {
          System.out.print(" " + i);
        }
        System.out.println();
      }
    }
  }


  public static List<Integer> solve(KeySet startKeys, Chest[] chests)
  {
    Set<Chest> startChests = new HashSet<Chest>();
    for (Chest c : chests)
    {
      startChests.add(c);
    }
    State startState = new State(startKeys, startChests);
    Deque<State> stack = new LinkedList<State>();
    stack.addLast(startState);
//    System.err.println("start: " + startState);
//    System.err.println("chests:");
//    for (Chest c : chests)
//    {
//      System.err.println(c.key + ": " + c.containedKeys);
//    }
    // depth first search
    Set<State> impossibleStates = new HashSet<State>();
    Set<State> path = new HashSet<State>();
    while (!stack.isEmpty())
    {
      State current = stack.peekLast();
      if (path.contains(current))
      {
        path.remove(current);
        impossibleStates.add(current);
        stack.removeLast();
//        System.err.println("failed: " + current);
        continue;
      }
      if (impossibleStates.contains(current))
      {
        // don't even try to add it to the path
        stack.removeLast();
//        System.err.println("ignore: " + current);
        continue;
      }
      path.add(current);
      if (current.remainingChests.isEmpty())
      {
        // find the current path
        List<Integer> result = new LinkedList<Integer>();
        State last = null;
        for (State s : stack)
        {
          if (path.contains(s))
          {
            if (last == null)
            {
              last = startState;
              continue;
            }
            // find the removed chest
            int removed = -1;
            for (Chest c : last.remainingChests)
            {
              if (!s.remainingChests.contains(c))
              {
                removed = c.number;
                break;
              }
            }
            result.add(removed);
            last = s;
          }
        }
        return result;
      }
      // add them in reverse order, so that we process them in order
      for (int i = chests.length - 1; i >= 0; --i)
      {
        Chest c = chests[i];
        if (current.remainingChests.contains(c) && current.keys.hasKey(c.key))
        {
          State nextState = current.copy();
          nextState.remainingChests.remove(c);
          nextState.keys.useKey(c.key);
          nextState.keys.addAll(c.containedKeys);
          // if we could unlock all the chests we have keys for, could we open all of the chests?
          KeySet allKeys = nextState.keys.copy();
          Set<Chest> chestsToOpen = new HashSet<Chest>(nextState.remainingChests);
          boolean changed = true;
          while (changed)
          {
            changed = false;
            Iterator<Chest> it = chestsToOpen.iterator();
            while (it.hasNext())
            {
              Chest test = it.next();
              if (allKeys.hasKey(test.key))
              {
                allKeys.addAll(test.containedKeys);
                it.remove();
                changed = true;
              }
            }
          }
          if (!chestsToOpen.isEmpty())
          {
//            System.err.println("missing key: " + nextState);
          }
          else
          {
            boolean enoughKeys = true;
            for (Chest test : nextState.remainingChests)
            {
              if (!allKeys.useKey(test.key))
              {
                enoughKeys = false;
                break;
              }
            }
            if (enoughKeys)
            {
//              System.err.println("adding: " + nextState);
              stack.add(nextState);
            }
          }
        }
      }
    }
    return null;
  }
}

final class State
{
  Set<Chest> remainingChests;
  KeySet keys;
  public State(KeySet keys, Set<Chest> remainingChests)
  {
    this.keys = keys;
    this.remainingChests = remainingChests;
  }
  State copy()
  {
    return new State(keys.copy(), new HashSet<Chest>(remainingChests));
  }
  public boolean equals(Object o)
  {
    if (!(o instanceof State))
    {
      return false;
    }
    State other = (State) o;
    if (remainingChests.size() != other.remainingChests.size())
    {
      return false;
    }
    if (!keys.equals(other.keys))
    {
      return false;
    }
    ArrayList<Chest> chests = new ArrayList<Chest>(remainingChests);
    ArrayList<Chest> otherChests = new ArrayList<Chest>(other.remainingChests);
    Collections.sort(chests);
    Collections.sort(otherChests);
    int len = chests.size();
    for (int i = 0; i < len; ++i)
    {
      if (!chests.get(i).equals(otherChests.get(i)))
      {
        return false;
      }
    }
    return true;
  }
  public int hashCode()
  {
    return 31 * keys.hashCode() + remainingChests.size();
  }
  public String toString()
  {
    StringBuffer buffer = new StringBuffer();
    buffer.append(keys);
    buffer.append("chests:");
    ArrayList<Chest> chests = new ArrayList<Chest>(remainingChests);
    Collections.sort(chests);
    for (Chest c : chests)
    {
      buffer.append(" " + c.number);
    }
    return buffer.toString();
  }
}

final class Chest implements Comparable<Chest>
{
  int number;
  int key;
  KeySet containedKeys;
  public Chest(int number, int key, KeySet containedKeys)
  {
    this.number = number;
    this.key = key;
    this.containedKeys = containedKeys;
  }
  public boolean equals(Object o)
  {
    if (!(o instanceof Chest))
    {
      return false;
    }
    Chest other = (Chest) o;
    return number == other.number;
  }
  public int hashCode()
  {
    return number;
  }
  public int compareTo(Chest c)
  {
    return number - c.number;
  }
}

final class KeySet
{
  Map<Integer, Integer> keyCounts;
  int numKeys;
  public KeySet()
  {
    keyCounts = new HashMap<Integer, Integer>();
    numKeys = 0;
  }
  public KeySet(int numKeys, Map<Integer, Integer> keyCounts)
  {
    this.numKeys = numKeys;
    this.keyCounts = keyCounts;
  }
  KeySet copy()
  {
    return new KeySet(numKeys, new HashMap<Integer, Integer>(keyCounts));
  }
  boolean hasKey(int key)
  {
    return keyCounts.containsKey(key);
  }
  void addKey(int key)
  {
    Integer count = keyCounts.get(key);
    numKeys++;
    if (count == null)
    {
      keyCounts.put(key, 1);
      return;
    }
    keyCounts.put(key, count + 1);
  }
  boolean addAll(KeySet other)
  {
    // returns true iff a new type of key is added
    boolean newType = false;
    for (Entry<Integer, Integer> entry : other.keyCounts.entrySet())
    {
      int key = entry.getKey();
      int toAdd = entry.getValue();
      Integer count = keyCounts.get(key);
      numKeys += toAdd;
      if (count == null)
      {
        keyCounts.put(key, toAdd);
        newType = true;
        continue;
      }
      keyCounts.put(key, count + toAdd);
    }
    return newType;
  }
  boolean useKey(int key)
  {
    Integer count = keyCounts.get(key);
    if (count == null)
    {
      return false;
    }
    count--;
    if (count == 0)
    {
      keyCounts.remove(key);
    }
    else
    {
      keyCounts.put(key, count);
    }
    numKeys--;
    return true;
  }
  public boolean equals(Object o)
  {
    if (!(o instanceof KeySet))
    {
      return false;
    }
    KeySet other = (KeySet) o;
    if (numKeys != other.numKeys)
    {
      return false;
    }
    for (Entry<Integer, Integer> entry : keyCounts.entrySet())
    {
      int key = entry.getKey();
      int count = entry.getValue();
      Integer value = other.keyCounts.get(key);
      if (value == null || value != count)
      {
        return false;
      }
    }
    for (Entry<Integer, Integer> entry : other.keyCounts.entrySet())
    {
      int key = entry.getKey();
      int count = entry.getValue();
      Integer value = keyCounts.get(key);
      if (value == null || value != count)
      {
        return false;
      }
    }
    return true;
  }
  public int hashCode()
  {
    return numKeys;
  }
  public String toString()
  {
    StringBuffer buffer = new StringBuffer();
    for (Entry<Integer, Integer> entry : keyCounts.entrySet())
    {
      buffer.append(entry.getKey() + "(x" + entry.getValue() + ") ");
    }
    return "[" + buffer.toString() + "]";
  }
}

